#ifndef PLAYER_H
#define PLAYER_H

#include "Move.h" 
#include "Board.h"

class Player {
    public:
        virtual Move getMove(Board*) = 0;
        virtual ~Player();
};

#endif