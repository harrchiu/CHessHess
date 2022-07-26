#include <vector>
#include <stdlib.h>
#include "Ai1.h"
#include "Move.h"

using namespace std;

Ai1::Ai1(PieceColour p) : Player{p} {}

Move Ai1::getMove(Board* b){
    bool isWhiteToMove = false;
    if (color == PieceColour::WHITE) {
        isWhiteToMove = true;
    }
    vector<Move> validMoves = b->getLegalMoves(isWhiteToMove);
    int randomNum = rand() % (int) validMoves.size();
    return validMoves.at(randomNum);
}
