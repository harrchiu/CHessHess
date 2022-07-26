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

Game::Game(Board *b) : board{b} {
    
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
                int pieceType = validPieces.find(toupper(inPiece));
                bool isWhite = inPiece == toupper(inPiece);

                unique_ptr<Piece> myPiece;

                switch (pieceType) {
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
                //Check Valid Square
                cin >> inSquare;
                if (inSquare.length() == 2) {
                    size_t x = cols.find(toupper(inSquare[0]));
                    size_t y = rows.find(inSquare[1]);
                    if (x != string::npos && y != string::npos) {
                        board->grid.at(y).at(x).piece = move(myPiece);
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
                size_t x = cols.find(toupper(inSquare[0]));
                size_t y = rows.find(inSquare[1]);
                if (x != string::npos && y != string::npos) {
                    board->grid.at(y).at(x).piece = nullptr;
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

string Game::playGame() {
    string cmd;
    while (true) {
        cin >> cmd;
        if (cmd.compare("move")) {
            Player* curPlayer;
            if (isWhiteToMove) {
                curPlayer = players[0];
            } else {
                curPlayer = players[1];
            }
            Move playerMove = curPlayer->getMove(board);
            if (attemptMove(playerMove)) {
                isWhiteToMove = !isWhiteToMove;
            }
        } else if (cmd.compare("resign")) {
            
        } else {
            cout << "Invalid Game Command" << endl;
        }

    }
}

bool Game::attemptMove(Move m) {
    vector<Move> validMoves = board->getLegalMoves(isWhiteToMove);
    for(int i=0;i<validMoves.size();i++) {
        if (validMoves[i].start == m.start && validMoves[i].end == m.end) {
            board->applyMove(validMoves[i]);
        }
    }
}
