#ifndef PLAYER
#define PLAYER

#include "Move.h" 
#include "Board.h"

class Player {
    public:
        Move getMove(Board &B);
};

#endif