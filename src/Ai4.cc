#include "Ai4.h"
#include "Move.h"

Ai4::Ai4(PieceColour p) : Player{p} {}

Move Ai4::getMove(Board* b){
    Move m(0,0,0,0, false);
    return m;
}
