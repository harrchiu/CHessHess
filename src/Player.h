#ifndef PLAYER_H
#define PLAYER_H

#include "Move.h" 
#include "Board.h"

// class to represent a chess player
class Player {
    protected:
        PieceColour color;
    public:
        Player(PieceColour);
        virtual ~Player();
        
        virtual Move getMove(Board*, bool isWhiteToMove = true) = 0;
};

#endif