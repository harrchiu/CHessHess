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

Game::Game(Board b) : board{b} {};

void Game::setup() {
    string cmd;
    bool keepGoing = true;
    string validPieces = "PRNBQK";
    string cols = "ABCDEFGH";
    string rows = "87654321";

    while (keepGoing) {
        cin >> cmd;
        // + Add Piece Case
        if (cmd.compare("+") == 0) {
            string inPiece;
            string inSquare;
            cin >> inPiece;
            //Check Valid Piece (Add Piece Case will end if not valid)
            if (validPieces.find(toupper(inPiece)) != string::npos) {
                int pieceType = validPieces.find(toupper(inPiece));
                switch pieceType: {
                    case PieceType::Pawn:
                        unique_ptr<Piece> myPiece(new Pawn());
                        break;
                    case PieceType::Rook:
                        unique_ptr<Piece> myPiece(new Rook());
                        break;
                    case PieceType::Knight:
                        unique_ptr<Piece> myPiece(new Knight());
                        break;
                    case PieceType::Bishop:
                        unique_ptr<Piece> myPiece(new Bishop());
                        break;
                    case PieceType::Queen:
                        unique_ptr<Piece> myPiece(new Queen());
                        break;
                    case PieceType::King:
                        unique_ptr<Piece> myPiece(new King());
                        break;
                    default:
                        break;
                }
                //Check Valid Square
                cin >> inSquare;
                if (inSquare.length() == 2) {
                    int x = cols.find(inSquare[0].toupper());
                    int y = rows.find(inSquare[1]);
                    if (x != string::npos && y != string::npos) {
                        board.grid.at(y).at(x).piece = myPiece;
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
        } else if (cmd.compare("-") == 0) {
            //Check Valid Square
            cin >> inSquare;
            if (inSquare.length() == 2) {
                int x = cols.find(inSquare[0].toupper());
                int y = rows.find(inSquare[1]);
                if (x != string::npos && y != string::npos) {
                    board.grid.at(y).at(x).piece = nullptr;
                    cout << "Piece at " << inSquare << " removed" << endl;
                } else {
                    cout << "Invalid Square" << endl;
                }
            } else {
                cout << "Invalid Square" << endl;
            }
        } else if (cmd.compare("=" == 0)) {
            string colour;
            cin >> colour;
            if (colour.toupper().compare("BLACK") == 0 || colour.toupper().compare("B")) {
                curTurn = PieceColour::Black;
                cout << "Black's Turn" << endl;
            } else if (colour.toupper().compare("WHITE") == 0 || colour.toupper().compare("W")) {
                curTurn = PieceColour::White;
                cout << "White's Turn" << endl;
            } else {
                cout << "Invalid Colour" << endl;
            }
        } else if (cmd.compare("done") == 0) {
            //Check for exactly one white king and one black king
            int whiteKingCount = 0;
            int blackKingCount = 0;
            for (auto vec : grid) {
                for (auto square : vec) {
                    if (square.piece && square.piece->type == PieceType::King){ 
                        if (square.piece->isWhite) {
                            ++whiteKingCount;
                        } else {
                            ++blackKingCount;
                        }
                    }
                }
            }
            if (whiteKingCount != 1) {
                cout << "Board must contain EXACTLY one white king" << endl;
            }
            if (blackKingCount != 1) {
                cout << "Board must contain EXACTLY one black king" << endl;
            }
            //Check for pawns in first and last row
            for (auto square : grid.at(0)) {
                if (square.piece && square.piece->type == PieceType::Pawn){
                    cout << "Pawns cannot be in first row" << endl;
                }
            }
            for (auto square : grid.back()) {
                if (square.piece && square.piece->type == PieceType::Pawn){
                    cout << "Pawns cannot be in last row" << endl;
                }
            }
            //Check that no king is in check
            pair<bool,bool> checkPair = isCheck();
            if (checkPair.first) {
                cout << "White king is in check" << endl;
            } if (checkPair.second) {
                cout << "Black king is in check" << endl;
            }
        }
    }    
}

void Game::setPlayer(PieceColour c, Player p) {
    players[c] = p;
};

string Game::playGame() {
    while (true) {
        Player curPlayer;
        if (isWhiteToMove) {
            curPlayer = players[0];
        } else {
            curPlayer = players[1];
        }
        Move playerMove = curPlayer.getMove(board);
        makeMove(playerMove);

    }
}

void Game::makeMove(Move m) {
    board.makeMove(m,isWhiteToMove);
    isWhiteToMove = !isWhiteToMove;
}