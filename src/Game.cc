#include <iostream>
#include <vector>
#include <string>
#include <math.h>

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
#include "State.h"

using namespace std;

// CTOR
Game::Game(Board *b) : isWhiteToMove{true}, board{b} {}

// DTOR
Game::~Game(){}

// setup - runs the entire setup mode process
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
            // Check Valid Piece (Add Piece Case will end if not valid)
            if (validPieces.find(toupper(inPiece)) != string::npos) {
                PieceType pieceType = (PieceType) validPieces.find(toupper(inPiece));
                bool isWhite = inPiece == toupper(inPiece);

                // Check Valid Square
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
            // Check Valid Square
            cin >> inSquare;
            if (inSquare.length() == 2) {
                size_t c = cols.find(toupper(inSquare[0]));
                size_t r = rows.find(inSquare[1]);
                if (c != string::npos && r != string::npos) {
                    board->setSquare(r,c,PieceType::EMPTY, true);
                    cout << "Piece at " << inSquare << " removed" << endl;
                } else {
                    cout << "Invalid Square" << endl;
                }
            } else {
                cout << "Invalid Square" << endl;
            }
        // = set colour Case
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
        } else if (cmd == "print") {
            display();
        } else if (cmd == "done") {
            //Check for exactly one white king and one black king
            keepGoing = false;
            int whiteKingCount = 0;
            int blackKingCount = 0;
            for (vector<Square>& vec : board->getBoard()) {
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
            //Check for no pawns in first and last row
            for (Square &square : board->getBoard().at(0)) {
                if (square.piece && square.piece->type() == PieceType::PAWN){
                    cout << "Pawns cannot be in first row" << endl;
                    keepGoing = true;
                }
            }
            for (Square &square : board->getBoard().back()) {
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

// strcmpNoCase - compares two strings without considering case
bool strcmpNoCase(string& a, string &b){
    for (int i=0;i< static_cast<int>(min(a.length(),b.length()));++i){
        if (toupper(a[i]) != toupper(b[i]))
            return false;
    }
    return a.length() == b.length();
}

// setPlayer - attachs a player to the game
void Game::setPlayer(PieceColour c, unique_ptr<Player> p) {
    players[c] = move(p);
};

// playGame - continuously asks for moves from both players, applying and 
// displaying them until the game is over. Returns the Outcome of the game
Outcome Game::playGame() {
    board->handleFENStart();     // setup initial FEN history

    cout << "Let's Play!" << endl;
    string cmd;
    while (true) {
        // Check if game is over
        if (board->getLegalMoves(isWhiteToMove).size() == 0) {
            if (board->isCheck(isWhiteToMove)) {
                if (isWhiteToMove) {
                    return Outcome::BLACK_VICTORY;
                } else {
                    return Outcome::WHITE_VICTORY;
                }
            } else {
                return Outcome::TIE;
            }
        }
        
        // Output turn instructions
        cout << (isWhiteToMove ? "WHITE" : "BLACK") 
                <<  " to play. Player options:" << endl
                << "- move <start square> <end square>" << endl
                << "- undo" << endl
                << "- resign" << endl;
        cout << "command: ";

        cin >> cmd;
        // Command case : move 
        if (cmd == "move") {
            // get move from current player
            Player* curPlayer;
            if (isWhiteToMove) {
                curPlayer = players[0].get();
            } else {
                curPlayer = players[1].get();
            }

            Move playerMove = curPlayer->getMove(board, isWhiteToMove);
            if (attemptMove(playerMove)) {
                isWhiteToMove = !isWhiteToMove;
                cout << playerMove << " was played!" << endl;
                display();
            // retry if not valid
            } else {
                cout << "Move was not valid!" << endl;
            }
        } 
        // Command case: an
        // process/play algebraic notation for sideToMove ("Na5") (if valid)
        else if (cmd == "an"){
            string move_AN;
            cin >> move_AN;
            vector<Move> legalMoves = board->getLegalMoves(isWhiteToMove);
            vector<string> legalMovesAN;

            for (Move &m:legalMoves){
                legalMovesAN.push_back(m.getAlgNotation(legalMoves));
            }  

            // try to find input in vector of moves converted to AN
            Move playerMove(-1,-1,-1,-1,isWhiteToMove);
            for (int mi=0;mi<(int)legalMoves.size();++mi){
                if (strcmpNoCase(move_AN, legalMovesAN[mi])){
                    playerMove = legalMoves[mi];
                    break;
                }
            }

            // if found, then play; otherwise input is invalid AN
            if (playerMove.start.first != -1 && attemptMove(playerMove)) {
                isWhiteToMove = !isWhiteToMove;
                cout << playerMove << " was played!" << endl;
                display();
            } else {
                cout << "Move was not valid!" << endl;
            }
        }
        // Command case : resign
        // end the game and return the correct outcome
        else if (cmd == "resign") {
            if (isWhiteToMove) {
                display(State::WHITE_RESIGN);   
                return Outcome::BLACK_VICTORY;
            } else {
                display(State::BLACK_RESIGN);  
                return Outcome::WHITE_VICTORY;
            }
        // Command case : undo
        // undo the last move if there is one.
        } else if (cmd == "undo") {
            if (board->undoLastMove(true)) {
                isWhiteToMove = !isWhiteToMove;
                cout << "Move was undone!" << endl;
                display();
            } else {
                cout << "No move to undo!" << endl;
            }
        } 
        // Command case : legal
        // print legal moves for both sides
        else if (cmd == "legal"){
            board->printLegalMoves();
        }
        // Command case : fen
        // print shortened-FEN for current board state
        else if (cmd == "fen"){
            cout << board->getFEN() << endl;
        }
        // Command case : history
        // print all played moves in algebraic notation
        else if (cmd == "history"){
            int n = (int) board->playedMoveList.size();
            if (!n) {
                cout << "No moves have been played." << endl;
                continue;
            }

            cout << n << " previous move" << (n != 1 ? "s" : "") << ": ";
            for (int i=0;i<n;++i){
                Move &m = board->playedMoveList[i];
                if (i != 0)
                    cout << ", ";
                cout << (char)(m.start.second + 'A') << (8 - m.start.first);
                cout << (char)(m.end.second + 'A') <<  (8 - m.end.first);
            }
            cout << endl;
        }
        // Command case: display
        // re-display the board
        else if (cmd == "display"){
            display();
        }
        // Command case : INVALID
        else {
            cout << "Invalid Game Command" << endl;
        }
    }
}

// attemptMove - see if move m is valid, apply to board if it is.
// returns whether or not the move was applied.
bool Game::attemptMove(Move m) {
    vector<Move> validMoves = board->getLegalMoves(isWhiteToMove);
    vector<Move> matchingMoves;

    //check how many valid moves match start/end square
    for(int i=0;i<(int)validMoves.size();++i) { 
        if (validMoves[i].start == m.start && validMoves[i].end == m.end) {
            matchingMoves.push_back(validMoves[i]);
        }
    }
    // ifonly 1 is matching, apply it
    if (matchingMoves.size() == (int)1) {   
        board->applyMove(matchingMoves.at(0),true);
        return true;
    }
    // if there is more than 1 matching
    // it is a promotion, get the promotion piece from cin and apply
    if (matchingMoves.size() > (int)1) {    
        string promoteTo;                   
        
        // move from algebraic notation would have promotion piece already
        PieceType pType = m.promotedTo;//PieceType::EMPTY;
        bool keepGoing = pType == PieceType::EMPTY;

        while(keepGoing) {
            cout << "Enter a valid promotion piece!" << endl;
            cin >> promoteTo;
            if (promoteTo.empty()) {
                continue;
            }
            keepGoing = false;
            switch (toupper(promoteTo[0])) {
                case 'R':
                    pType = PieceType::ROOK;
                    break;
                case 'N':
                    pType = PieceType::KNIGHT;
                    break;
                case 'B':
                    pType = PieceType::BISHOP;
                    break;
                case 'Q':
                    pType = PieceType::QUEEN;
                    break;
                default:
                    keepGoing = true;
            }
        }
        for(int i=0;i<(int)matchingMoves.size();++i) {
            if (matchingMoves.at(i).promotedTo == pType) {
                board->applyMove(matchingMoves.at(i),true);
                return true;
            }
        }
    }
    return false;
}

// display - displays 
void Game::display(State s) {
    bool inCheck = board->isCheck(isWhiteToMove);
    bool noValidMoves = board->getLegalMoves(isWhiteToMove).size() == 0;
    
    // calculate the state based on inCheck, if there are valid moves,
    // and who's turn it is
    State state;
    if (s != State::REGULAR) {
        state = s;
    }
    else {
        state = State::REGULAR;
        if (inCheck) {
            if (noValidMoves) {
                if (isWhiteToMove) {
                    state = State::BLACK_WIN;
                } else {
                    state = State::WHITE_WIN;
                }
            } else {
                if (isWhiteToMove) {
                    state = State::WHITE_CHECK;
                } else {
                    state = State::BLACK_CHECK;
                }
            }
        } else {
            if (noValidMoves) {
                state = State::STALEMATE;
            }
        }
    }

    //display the board with that state
    board->display(state);
}

