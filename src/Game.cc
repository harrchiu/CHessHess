#include <iostream>
#include <vector>
#include <string>

#include "Game.h"
#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Square.h"

using namespace std;

Game::Game(Board *b) : isWhiteToMove{true}, board{b} {
    
}

Game::~Game(){
    delete players[0];
    delete players[1];
}

void Game::setup() {
    string cmd;
    bool keepGoing = true;
    string validPieces = "PRNBQK";
    string cols = "ABCDEFGH";
    string rows = "87654321";

    while (keepGoing) {
        char inPiece;
        string inSquare;
        cin >> cmd;
        // + Add Piece Case
        if (cmd == "+") {
            cin >> inPiece;
            //Check Valid Piece (Add Piece Case will end if not valid)
            if (validPieces.find(toupper(inPiece)) != string::npos) {
                PieceType pieceType = (PieceType) validPieces.find(toupper(inPiece));
                bool isWhite = inPiece == toupper(inPiece);

                //Check Valid Square
                cin >> inSquare;
                if (inSquare.length() == 2) {
                    size_t c = cols.find(toupper(inSquare[0]));
                    size_t r = rows.find(inSquare[1]);
                    if (c != string::npos && r != string::npos) {
                        board->setSquare(r,c,pieceType,isWhite);
                        cout << inPiece << " added at " << inSquare << endl;
                    } else {
                        cout << "Invalid Square" << endl;
                    }
                } else {
                    cout << "Invalid Square" << endl;
                }
            } else {
                cout << "Invalid Piece" << endl;
            }
        // - Remove Piece Case
        } else if (cmd == "-") {
            //Check Valid Square
            cin >> inSquare;
            if (inSquare.length() == 2) {
                size_t c = cols.find(toupper(inSquare[0]));
                size_t r = rows.find(inSquare[1]);
                if (c != string::npos && r != string::npos) {
                    board->grid.at(r).at(c).piece = nullptr;
                    cout << "Piece at " << inSquare << " removed" << endl;
                } else {
                    cout << "Invalid Square" << endl;
                }
            } else {
                cout << "Invalid Square" << endl;
            }
        } else if (cmd == "=") {
            string colour;
            cin >> colour;
            if (colour[0] == 'B' || colour[0] == 'b') {
                isWhiteToMove = false;
                cout << "Black's Turn" << endl;
            } else if (colour[0] == 'W' || colour[0] == 'w') {
                isWhiteToMove = true;
                cout << "White's Turn" << endl;
            } else {
                cout << "Invalid Colour" << endl;
            }
        } else if (cmd == "done") {
            //Check for exactly one white king and one black king
            keepGoing = false;
            int whiteKingCount = 0;
            int blackKingCount = 0;
            for (vector<Square>& vec : board->grid) {
                for (Square &square : vec) {
                    if (square.piece && square.piece->type() == PieceType::KING){ 
                        if (square.piece->getIsWhite()) {
                            ++whiteKingCount;
                        } else {
                            ++blackKingCount;
                        }
                    }
                }
            }
            if (whiteKingCount != 1) {
                cout << "Board must contain EXACTLY one white king" << endl;
                keepGoing = true;
            }
            if (blackKingCount != 1) {
                cout << "Board must contain EXACTLY one black king" << endl;
                keepGoing = true;
            }
            //Check for pawns in first and last row
            for (Square &square : board->grid.at(0)) {
                if (square.piece && square.piece->type() == PieceType::PAWN){
                    cout << "Pawns cannot be in first row" << endl;
                    keepGoing = true;
                }
            }
            for (Square &square : board->grid.back()) {
                if (square.piece && square.piece->type() == PieceType::PAWN){
                    cout << "Pawns cannot be in last row" << endl;
                    keepGoing = true;
                }
            }
            //Check that no king is in check
            bool isWhiteInCheck = board->isCheck(true);
            bool isBlackInCheck = board->isCheck(false);
            if (isWhiteInCheck) {
                cout << "White king is in check" << endl;
                keepGoing = true;
            } if (isBlackInCheck) {
                cout << "Black king is in check" << endl;
                keepGoing = true;
            }
        }
    }    
}

void Game::setPlayer(PieceColour c, Player* p) {
    players[c] = p;
};

Outcome Game::playGame() {
    cout << "Lets Play!" << endl;
    string cmd;
    while (true) {
        board->printLegalMoves();
        
        cin >> cmd;
        if (cmd.compare("move") == 0) {
            cout << "Make your move" << endl;
            Player* curPlayer;
            if (isWhiteToMove) {
                curPlayer = players[0];
            } else {
                curPlayer = players[1];
            }
            Move playerMove = curPlayer->getMove(board);
            if (attemptMove(playerMove)) {
                isWhiteToMove = !isWhiteToMove;
                cout << "Move was made!" << endl;
                display();
            } else {
                cout << "Move was not valid!" << endl;
            }
        } else if (cmd.compare("resign")) {
            if (isWhiteToMove) {
                return Outcome::WHITE_RESIGN;
            } else {
                return Outcome::BLACK_RESIGN;
            }
        } else {
            cout << "Invalid Game Command" << endl;
        }
        
        if (board->getLegalMoves(isWhiteToMove).size() == 0) {
            if (board->isCheck(isWhiteToMove)) {
                if (isWhiteToMove) {
                    return Outcome::BLACK_WIN;
                } else {
                    return Outcome::WHITE_WIN;
                }
            } else {
                return Outcome::STALEMATE;
            }
        }
    }
}

bool Game::attemptMove(Move m) {
    vector<Move> validMoves = board->getLegalMoves(isWhiteToMove);

    for(int i=0;i<(int)validMoves.size();i++) {
        if (validMoves[i].start == m.start && validMoves[i].end == m.end) {
            board->applyMove(validMoves[i]);
            return true;
        }
    }

    return false;       // TODO: ALBERT  FIX THIS
}

void Game::display() {
    board->display();

    cout << "REPLACE THIS WITH WINNING MESSAGE" << endl;
}
