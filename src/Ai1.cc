#include <vector>
#include <stdlib.h>
#include "Ai1.h"
#include "Move.h"

using namespace std;

Ai1::Ai1(PieceColour p) : Player{p} {}

Move Ai1::getMove(Board* b){
    vector<Move> validMoves = b->getLegalMoves(color);
    int randomNum = rand() % (int) validMoves.size();
    return validMoves.at(randomNum);
}
