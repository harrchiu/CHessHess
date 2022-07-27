#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Ai2.h"
#include "Move.h"

using namespace std;

// CTOR
Ai2::Ai2(PieceColour p) : Player{p} {}

// getMove - gets a move from the AI to be performed
Move Ai2::getMove(Board* b, bool isWhiteToMove){
    // gets a vector of valid moves from the board
    vector<Move> validMoves = b->getLegalMoves(!color);
    
    vector<Move> captures;
    vector<Move> checks;
    for(int i=0;i<(int)validMoves.size();i++) {
        // if a piece is captured add the move to "captures"
        if (validMoves.at(i).capturedPiece != PieceType::EMPTY) {
            captures.push_back(validMoves.at(i));
        }
        
        // if the opponent is in check after applying the move,
        // add the move to "checks"
        b->applyMove(validMoves.at(i));
        if (color == PieceColour::WHITE) {
            if (b->isCheck(false,false)) {
                checks.push_back(validMoves.at(i));
            }
        } else {
            if (b->isCheck(true,false)) {
                checks.push_back(validMoves.at(i));
            }
        }
        b->undoLastMove();
    }

    // seed the random number
    srand ( time(NULL) );

    // if there are capture moves return a random one
    if (!captures.empty()) {
        int randomNum = rand() % (int) captures.size();
        return captures.at(randomNum);
    }

    // if there are check moves return a random one
    if (!checks.empty()) {
        int randomNum = rand() % (int) checks.size();
        return checks.at(randomNum);
    }

    // else return a random valid move
    int randomNum = rand() % ((int) validMoves.size());
    return validMoves.at(randomNum);
}
