#ifndef PLAYER_H
#define PLAYER_H

#include "Move.h" 
#include "Board.h"

class Player {
    public:
        Move getMove(Board &B);
};

#endif