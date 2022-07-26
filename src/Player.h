#ifndef PLAYER_H
#define PLAYER_H

#include "Move.h" 
#include "Board.h"

class Player {
    protected:
        PieceColour color;
    public:
        virtual Move getMove(Board*) = 0;
        Player(PieceColour);
        virtual ~Player();
};

#endif