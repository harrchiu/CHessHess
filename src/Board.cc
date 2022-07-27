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

// helper methods
std::pair<int,int> Board::getKingCoords(bool isKingWhite) {
    for (int r=0;r<rows;++r){
        for (int c=0;c<cols;++c){
            Piece* p = grid[r][c].piece.get();
            if (p && p->type() == PieceType::KING && 
                p->getIsWhite() == isKingWhite){
                return {r,c};
            }
        }
    }
    return {-1,-1};
}

bool Board::isOnBoard(const int r, const int c){
    return r >= 0 && c >= 0 && r < rows && c < cols;
}

vector<Move> Board::getMoves(bool isWhiteToMove, bool disableCastle) {
    vector<Move> moves;

    bool hasKingMoved = hasSquareBeenTouched(isWhiteToMove ? 7 : 0, 4);
    if (hasKingMoved){}

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

                            if (destType == PieceType::EMPTY) {
                                isValid = pm.canDestBeEmpty;
                            } else if (destPiece->getIsWhite()) {
                                isValid = pm.canDestBeWhite; 
                                breakAfter = true;
                            }
                            else {
                                isValid = pm.canDestBeBlack;
                                breakAfter = true;
                            }
                            break;
                        }
                        case MoveType::CASTLE_K_SIDE: {
                            if (disableCastle) break;
                            int backR = isWhiteToMove ? 7 : 0;
                            Piece* p = grid[backR][0].piece.get();
                            if (!p || p->type() != PieceType::ROOK) break;
                            
                            if (hasKingMoved || hasSquareBeenTouched(backR, 7))
                                break;
                            if (isCheck(isWhiteToMove, true)) break;
                            if (canReach(!isWhiteToMove,backR,5,true)) break;
                            if (grid[backR][5].piece || grid[backR][6].piece)
                                break;

                            isValid = true;
                            break;
                        }
                        case MoveType::CASTLE_Q_SIDE: {
                            if (disableCastle) break;
                            int backR = isWhiteToMove ? 7 : 0;
                            Piece* p = grid[backR][0].piece.get();
                            if (!p || p->type() != PieceType::ROOK) break;

                            if (hasKingMoved || hasSquareBeenTouched(backR, 0))
                                break;
                            if (isCheck(isWhiteToMove, true)) break;
                            if (canReach(!isWhiteToMove,backR,4, true)) break;
                            if (grid[backR][1].piece || grid[backR][2].piece ||
                                grid[backR][3].piece)
                                break;

                            isValid = true;
                            break;
                        }
                        case MoveType::EN_PASSANT: {
                            if (playedMoveList.empty()) break;
                            Move m = playedMoveList.back();
                            if (m.moveType != MoveType::DOUBLE_PAWN) break;

                            if (r == m.end.first && newC == m.end.second){
                                isValid = true;
                            }
                            break;
                        }
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
        grid.at(m.start.first).at(3).piece = 
            move(grid.at(m.start.first).at(0).piece);
    //If CASTLE_K, move grid[startX][7](rook) -> grid[c][5] 
    } else if (m.moveType == MoveType::CASTLE_K_SIDE) {
        grid.at(m.start.first).at(5).piece = 
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
    previousFENs.push_back(getFEN());

    if (updateDisplay){
        td.update(m);
        gd.update(m);
        if (isThreeFold()){
            cout << "*************************************" << endl;
            cout << "Position has been reached three times." << endl;
        }
    }
}                   

// returns whether a move was successfully undone
bool Board::undoLastMove(bool updateDisplay){
    if (playedMoveList.empty()) return false;
    Move m = playedMoveList.back();
    playedMoveList.pop_back();
    previousFENs.pop_back();

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
        grid.at(m.end.first).at(m.end.second).piece = move(p);
    }

    if (updateDisplay) {
        td.restore(m);
        gd.restore(m);
    }

    return true;
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
            myPiece = nullptr;
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
bool Board::isCheck(bool isSideWhite, bool disableCastle) {
    vector<Move> opponentMoves = getMoves(!isSideWhite, disableCastle);

    for (Move m : opponentMoves){
        // must be the opposing, since this is a "doable" move
        if (m.capturedPiece == PieceType::KING){
            return true;
        }
    }

    return false;
}

// can SIDE reach the square (r,c)
bool Board::canReach(bool isSideWhite, int r, int c, bool disableCastle){
    vector<Move> moves = getMoves(isSideWhite, disableCastle);
    for (Move m : moves){
        if (m.end.first == r && m.end.second == c){
            return true;
        }
    }
    return false;
}

// was there a prev. move starting or ending at (r,c)
bool Board::hasSquareBeenTouched(int r, int c){
    for (Move m : playedMoveList){
        if ((m.start.first == r && m.start.second == c) ||
            (m.end.first == r && m.end.second == c)){
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
    for (int i=0;i<(int)whiteMoves.size();++i) {
        cout << whiteMoves[i].getAlgNotation(whiteMoves);
        if (i != (int)whiteMoves.size()-1) cout  << ", ";
    }

    cout << endl << blackMoves.size() << " legal moves for black: ";
    for (int i=0;i<(int)blackMoves.size();++i) {
        cout << blackMoves[i].getAlgNotation(blackMoves);
        if (i != (int)blackMoves.size()-1) cout  << ", ";
    }
    cout << endl;
}

// get a shortened version of FEN string-representation of current board state
string Board::getFEN() {
    int prevEmpty = 0;
    string s;

    for (int r=0;r<rows;++r){
        if (r != 0) s += '/';
        for (int c=0;c<cols;++c){
            if (grid[r][c].piece == nullptr){
                ++prevEmpty;
            }
            else{
                if (prevEmpty){
                    s += '0' + prevEmpty;
                    prevEmpty = 0;
                }
                char pc = Piece::letters[grid[r][c].piece->type()];
                if (grid[r][c].piece->getIsWhite())
                    s += toupper(pc);
                else
                    s += pc;
            }
        }
        if (prevEmpty) {
            s += '0' + prevEmpty;
            prevEmpty = 0;
        }
    }

    return s;
}

// check if the current position has been reached for the 3rd time or more
bool Board::isThreeFold() {
    if (previousFENs.empty()) return false;
    string currentFEN = previousFENs.back();

    int count = 1;
    for (int i=previousFENs.size()-2;i>=0;--i){
        if (previousFENs[i] == currentFEN){
            if (++count == 3){
                return true;
            }
        }
    }
    return false;
}

// put the initial position in previous FENs
void Board::handleFENStart() {
    previousFENs = {getFEN()};
}