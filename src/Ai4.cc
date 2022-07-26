#include "Ai4.h"
#include "Move.h"

//CTOR
Ai4::Ai4(PieceColour p) : Player{p} {}

// getMove - gets a move from the AI to be performed
Move Ai4::getMove(Board* b){
    Move m(0,0,0,0, false);
    return m;
}
