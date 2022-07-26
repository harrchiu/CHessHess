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
        grid[1][c].piece = make_unique<Pawn>(false);
        grid[6][c].piece = make_unique<Pawn>(true);
    }

    // rest
    for (int r: {0,7}){
        grid[r][0].piece = make_unique<Rook>(r == 7);
        grid[r][1].piece = make_unique<Knight>(r == 7);
        grid[r][2].piece = make_unique<Bishop>(r == 7);
        grid[r][3].piece = make_unique<Queen>(r == 7);
        grid[r][4].piece = make_unique<King>(r == 7);
        grid[r][5].piece = make_unique<Bishop>(r == 7);
        grid[r][6].piece = make_unique<Knight>(r == 7);
        grid[r][7].piece = make_unique<Rook>(r == 7);
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
                    PieceType promotedTo = PieceType::EMPTY;

                    bool isValid = true;
                    switch (pm.mt){
                        case MoveType::NORMAL:
                            if (destType == PieceType::EMPTY)
                                isValid = pm.canDestBeEmpty;
                            else {
                                isValid = destPiece->getIsWhite()
                                    == pm.canDestBeWhite; 
                            }
                            break;
                        case MoveType::CASTLE_K_SIDE:
                            break;
                        case MoveType::CASTLE_Q_SIDE:
                            break;
                        case MoveType::EN_PASSANT:
                            break;
                        case MoveType::DOUBLE_PAWN:
                            break;
                        case MoveType::PROMOTION:
                            break;
                    }
                    if (!isValid) break;

                    moves.push_back(Move(r,c,newR,newC,curPiece->type(), 
                        destType, promotedTo));
                    //     // capture?
                    //     // enpassant?
                    //     // first move?
                    //     // castling
                    // if (grid)
                    
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

        undoLastMove(m);
    }
    return legalMoves;
}

// precondition: move is valid
void Board::applyMove(Move& m) {
    if (m.moveType == MoveType::CASTLE_Q_SIDE) {
        grid.at(m.start.first).at(3).piece = move(grid.at(m.start.first).at(0).piece);
    } else if (m.moveType == MoveType::CASTLE_K_SIDE) {
        grid.at(m.start.first).at(5).piece = move(grid.at(m.start.first).at(7).piece);
    } else if (m.moveType == MoveType::EN_PASSANT) {
        grid.at(m.start.first).at(m.end.second).piece.release();
    } else if (m.moveType == MoveType::PROMOTION) {
        switch (m.promotedTo) {
            case PieceType::ROOK:
                grid.at(m.start.first).at(m.end.first).piece = make_unique<Rook>(grid.at(m.start.first).at(m.end.first).piece->getIsWhite());
                break;
            case PieceType::KNIGHT:
                grid.at(m.start.first).at(m.end.first).piece = make_unique<Knight>(grid.at(m.start.first).at(m.end.first).piece->getIsWhite());
                break;
            case PieceType::BISHOP:
                grid.at(m.start.first).at(m.end.first).piece = make_unique<Bishop>(grid.at(m.start.first).at(m.end.first).piece->getIsWhite());
                break;
            case PieceType::QUEEN:
                grid.at(m.start.first).at(m.end.first).piece = make_unique<Queen>(grid.at(m.start.first).at(m.end.first).piece->getIsWhite());
                break;
            default:
                break;
        }
    } 
    grid.at(m.end.first).at(m.end.second).piece = move(grid.at(m.start.first).at(m.end.first).piece);
}                   

void Board::undoLastMove(Move& m){

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

void Board::display() {
    td.display();
    gd.display();
}
