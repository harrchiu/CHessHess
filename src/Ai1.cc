#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Ai1.h"
#include "Move.h"

using namespace std;

// CTOR
Ai1::Ai1(PieceColour p) : Player{p} {}

// getMove - gets a move from the AI to be performed
Move Ai1::getMove(Board* b, bool isWhiteToMove){
    // Gets a vector of valid moves from the board based on player colour
    // bool isWhiteToMove = false;
    // if (color == PieceColour::WHITE) {
    //     isWhiteToMove = true;
    // }
    vector<Move> validMoves = b->getLegalMoves(isWhiteToMove);

    // Returns a random move from the vector
    srand ( time(NULL) );
    int randomNum = rand() % (int) validMoves.size();
    return validMoves.at(randomNum);
}
