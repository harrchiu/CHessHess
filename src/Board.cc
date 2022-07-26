#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "Board.h"
#include "Piece.h"
#include "Square.h"
#include "Move.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "Display.h"
#include "TextualDisplay.h"
#include "GraphicalDisplay.h"

using namespace std;

// initialize board to empty position
Board::Board(int rows, int cols) : rows{rows}, cols{cols}, td{TextualDisplay{rows, cols}}, gd{GraphicalDisplay{rows, cols}} {
    for (int i=0;i<rows;++i){
        vector<Square> cRow;
        for (int j=0;j<cols;++j){
            cRow.emplace_back(i,j,nullptr);
        }
        grid.push_back(cRow);
    }
}

// l-value/deep copy ctor
// Board::Board(const Board& o) : rows{o.rows}, cols{o.cols} {
//     for (int i=0;i<rows;++i){
//         vector<Square> cRow;
//         for (int j=0;j<cols;++j){
//             Piece* copyPiece = nullptr;
//             if (grid[i][j].piece){
//                 copyPiece = new Piece(grid[i][j].piece);
//             }
//             cRow.push_back(Square(i,j,copyPiece));
//         }
//         grid.push_back(cRow);
//     }
// }

// assume board is empty (not deleting pieces)
void Board::setupInitialPosition() {
    // vector<vector<Piece*>> piecePtrs = {
    //     {new Rook(false),new Knight(false),new Bishop(false),new Queen(false),
    //     new King(false),new Bishop(false),new Knight(false),new Rook(false)},
    //     {new Pawn(false), new Pawn(false), new Pawn(false), new Pawn(false),
    //     new Pawn(false), new Pawn(false), new Pawn(false), new Pawn(false)},

    //     {new Rook(true),new Knight(true),new Bishop(true),new Queen(true),
    //     new King(true),new Bishop(true),new Knight(true),new Rook(true)},
    //     {new Pawn(true), new Pawn(true), new Pawn(true), new Pawn(true),
    //     new Pawn(true), new Pawn(true), new Pawn(true), new Pawn(true)}
    // };
    // vector<int> startingRows = {0,1,6,7};

    // for (int r: startingRows){
    //     for (int c=0;c<8;++c){
    //         grid[r][c].piece = make_unique(piecePtrs[r][c];
    //     }
    // }

    // pawns
    for (int c=0;c<8;++c){
        setSquare(1, c, PieceType::PAWN, false);
        setSquare(6, c, PieceType::PAWN, true);
    }

    // rest
    for (int r: {0,7}){
        setSquare(r, 0, PieceType::ROOK,   r == 7);
        setSquare(r, 1, PieceType::KNIGHT, r == 7);
        setSquare(r, 2, PieceType::BISHOP, r == 7);
        setSquare(r, 3, PieceType::QUEEN,  r == 7);
        setSquare(r, 4, PieceType::KING,   r == 7);
        setSquare(r, 5, PieceType::BISHOP, r == 7);
        setSquare(r, 6, PieceType::KNIGHT, r == 7);
        setSquare(r, 7, PieceType::ROOK,   r == 7);
    }
}

Board::~Board() {
    // changed to unique ptr so not necessary?

    // for (int i=0;i<rows;++i){
    //     for (int j=0;j<cols;++j){
    //         if (grid[i][j].piece){
    //             delete grid[i][j].piece;
    //         }
    //     }
    // }
}

int Board::getRows() { return rows; };
int Board::getCols() { return cols; };
bool Board::isOnBoard(const int r, const int c){
    return r >= 0 && c >= 0 && r < rows && c < cols;
}

bool Board::isMate(bool isSideWhite) {
    bool checkStatus = isCheck(isSideWhite);
    return getLegalMoves(isSideWhite).size() == 0 && checkStatus;
};


vector<Move> Board::getMoves(bool isWhiteToMove) {
    vector<Move> moves;

    for (int r=0;r<rows;++r){
        for (int c=0;c<cols;++c){

            // must be a non-empty piece of the same color
            Piece* curPiece = grid[r][c].piece.get();
            if (nullptr == curPiece) continue;
            if (curPiece->getIsWhite() != isWhiteToMove) continue;

            // e.g. dirs is all the moves going right
            for (vector<PotentialMove> dirs : curPiece->getMoveDirections()){
                for (PotentialMove pm : dirs){
                    int newR = r + pm.rowMov;
                    int newC = c + pm.colMov;
                    if (!isOnBoard(newR, newC)) break;
                    
                    Piece* destPiece = grid[newR][newC].piece.get();
                    PieceType destType = destPiece ? destPiece->type() 
                        : PieceType::EMPTY;
                    vector<PieceType> promotedTos = {EMPTY};

                    bool isValid = false;
                    bool breakAfter = false;    // stop looking as soon as we captured a piece
                    switch (pm.mt){
                        case MoveType::NORMAL: {
                            if (curPiece->type() == PieceType::PAWN){   // save for promo
                                if (newR == 0 || newR == 7){
                                    break;
                                }
                            }

                            if (destType == PieceType::EMPTY)
                                isValid = pm.canDestBeEmpty;
                            else if (destPiece->getIsWhite()){
                                isValid = pm.canDestBeWhite; 
                                breakAfter = true;
                            }
                            else{
                                isValid = pm.canDestBeBlack;
                                breakAfter = true;
                            }
                            break;
                        }
                        case MoveType::CASTLE_K_SIDE:
                            break;
                        case MoveType::CASTLE_Q_SIDE:
                            break;
                        case MoveType::EN_PASSANT:
                            break;
                        case MoveType::DOUBLE_PAWN: {
                            if (r != 1 && r != 6) break;
                            int vertDir = pm.rowMov/2;  // moved by 2
                            isValid = grid[newR][newC].piece == nullptr &&
                                grid[r + vertDir][newC].piece == nullptr;
                            break;
                        }
                        case MoveType::PROMOTION: {
                            if (newR != 0 && newR != 7) break;
                            if (destType == PieceType::EMPTY){
                                if (!pm.canDestBeEmpty)
                                    break;
                            }
                            else if (destPiece->getIsWhite()){
                                if (!pm.canDestBeWhite)
                                    break; 
                            }
                            else {
                                if (!pm.canDestBeBlack) break;
                            }

                            promotedTos = {QUEEN, ROOK, BISHOP, KNIGHT};
                            isValid = true;
                            break;
                        }
                    }
                    if (!isValid) break;

                    for (PieceType pt:promotedTos){
                        moves.push_back(Move(r,c,newR,newC,isWhiteToMove,pm.mt,
                            curPiece->type(), destType, pt));
                    }

                    if (breakAfter) break;
                }
            }

        }
    }
    return moves;
}

// here we go
vector<Move> Board::getLegalMoves(bool isWhiteToMove) {
    vector<Move> moves = getMoves(isWhiteToMove);
    vector<Move> legalMoves = {};
    for (Move m : moves) {

        applyMove(m);

        if (!isCheck(isWhiteToMove)){
            legalMoves.push_back(m);
        }

        undoLastMove();
    }
    return legalMoves;
}

// precondition: move is valid
void Board::applyMove(Move& m, bool updateDisplay) {
    if (m.moveType == MoveType::CASTLE_Q_SIDE) {
            move(grid.at(m.start.first).at(0).piece);
    //If CASTLE_K, move grid[startX][7](rook) -> grid[c][5] 
    } else if (m.moveType == MoveType::CASTLE_K_SIDE) {
            move(grid.at(m.start.first).at(7).piece);
    //If EN_PASSANT, remove grid[startX][endY]
    } else if (m.moveType == MoveType::EN_PASSANT) {
        grid.at(m.start.first).at(m.end.second).piece.release();
    //If PROMOTE, change grid[startX][startY](the pawn before moving) 
    } else if (m.moveType == MoveType::PROMOTION) {
        switch (m.promotedTo) {
            case PieceType::ROOK:
                grid.at(m.start.first).at(m.start.second).piece = 
                    make_unique<Rook>(grid
                                    .at(m.start.first)
                                    .at(m.start.second).piece->getIsWhite());
                break;
            case PieceType::KNIGHT:
                grid.at(m.start.first).at(m.start.second).piece = 
                    make_unique<Knight>(grid
                                    .at(m.start.first)
                                    .at(m.start.second).piece->getIsWhite());
                break;
            case PieceType::BISHOP:
                grid.at(m.start.first).at(m.start.second).piece = 
                    make_unique<Bishop>(grid
                                    .at(m.start.first)
                                    .at(m.start.second).piece->getIsWhite());
                break;
            case PieceType::QUEEN:
                grid.at(m.start.first).at(m.start.second).piece = 
                    make_unique<Queen>(grid
                                    .at(m.start.first)
                                    .at(m.start.second).piece->getIsWhite());
                break;
            default:
                break;
        }
    }
    //Now move the piece from the start to the end square (auto overwrites)
    grid.at(m.end.first).at(m.end.second).piece = 
        move(grid.at(m.start.first).at(m.start.second).piece);
    playedMoveList.push_back(m);

    if (updateDisplay){
        td.update(m);
        gd.update(m);
    }
}                   



void Board::undoLastMove(){

    if (playedMoveList.empty()) return;
    Move m = playedMoveList.back();
    playedMoveList.pop_back();

    //If CASTLE_Q, reverse the rook move 
    if (m.moveType == MoveType::CASTLE_Q_SIDE) {
        grid.at(m.start.first).at(0).piece = 
            move(grid.at(m.start.first).at(3).piece);
    //If CASTLE_K, reverse the rook move
    } else if (m.moveType == MoveType::CASTLE_K_SIDE) {
        grid.at(m.start.first).at(7).piece = 
            move(grid.at(m.start.first).at(5).piece);
    //If EN_PASSANT, add the taken pawn back
    } else if (m.moveType == MoveType::EN_PASSANT) {
        grid.at(m.start.first).at(m.end.second).piece = 
            make_unique<Pawn>(!grid
                                .at(m.end.first)
                                .at(m.end.second).piece->getIsWhite()); 
                                    // not the colour of the attacking piece
    //If PROMOTE, change the piece back to a pawn
    } else if (m.moveType == MoveType::PROMOTION) {     // smart!
        grid.at(m.end.first).at(m.end.second).piece = 
            make_unique<Pawn>(grid
                            .at(m.end.first)
                            .at(m.end.second).piece->getIsWhite());
    } 
    //Move the piece at end back to start square
    grid.at(m.start.first).at(m.start.second).piece =
         move(grid.at(m.end.first).at(m.end.second).piece);
    //If a piece was captured not through en_passent, add it back to the 
    //end square
    if (m.capturedPiece != PieceType::EMPTY && m.moveType != MoveType::EN_PASSANT) {
        // m.moveType == MoveType::PROMOTION
        unique_ptr<Piece> p;
        bool isWhite = !grid.at(m.start.first).at(m.start.second).piece->getIsWhite();
        switch (m.capturedPiece) {
            case PieceType::PAWN:
                p = make_unique<Pawn>(isWhite);
                break;
            case PieceType::ROOK:
                p = make_unique<Rook>(isWhite);
                break;
            case PieceType::KNIGHT:
                p = make_unique<Knight>(isWhite);
                break;
            case PieceType::BISHOP:
                p = make_unique<Bishop>(isWhite);
                break;
            case PieceType::QUEEN:
                p = make_unique<Queen>(isWhite);
                break;
            case PieceType::KING:
                p = make_unique<King>(isWhite);
                break;
            default:
                break;
        }
        // bruh didnt actually set the pointer to the new piece
        grid.at(m.end.first).at(m.end.second).piece = move(p);
    }
}

void Board::setSquare(int r, int c, PieceType pType, bool isWhite) {
    unique_ptr<Piece> myPiece;
    switch (pType) {
        case PieceType::PAWN:
            myPiece = make_unique<Pawn>(isWhite);
            break;
        case PieceType::ROOK:
            myPiece = make_unique<Rook>(isWhite);
            break;
        case PieceType::KNIGHT:
            myPiece = make_unique<Knight>(isWhite);
            break;
        case PieceType::BISHOP:
            myPiece = make_unique<Bishop>(isWhite);
            break;
        case PieceType::QUEEN:
            myPiece = make_unique<Queen>(isWhite);
            break;
        case PieceType::KING:
            myPiece = make_unique<King>(isWhite);
            break;
        default:
            break;
    }
    grid.at(r).at(c).piece = move(myPiece);
    td.setSquare(r, c, pType, isWhite);
    gd.setSquare(r, c, pType, isWhite);
}

vector<vector<Square>>& Board::getBoard() {
    return grid;
}

// go through all opponent (including illegal) moves and check if they
// capture the king
bool Board::isCheck(bool isSideWhite) {
    vector<Move> opponentMoves = getMoves(!isSideWhite);

    for (Move m : opponentMoves){
        // must be the opposing, since this is a "doable" move
        if (m.capturedPiece == PieceType::KING){
            return true;
        }
    }

    return false;
}

void Board::display(State s) {
    td.display(s);
    gd.display(s);
}

void Board::printLegalMoves() {
     // print all legal moves
    vector<Move> whiteMoves = getLegalMoves(true);
    vector<Move> blackMoves = getLegalMoves(false);

    cout << whiteMoves.size() << " legal moves for white: ";
    for (Move m: whiteMoves) {
        cout << m << ", ";
    }

    cout << endl << blackMoves.size() << " legal moves for black: ";
    for (Move m: blackMoves) {
        cout << m << ", ";
    }
    cout << endl;
}
