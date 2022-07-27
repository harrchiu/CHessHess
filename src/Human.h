#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h" 

// class to represent a human player
class Human : public Player {
    public:
        Human(PieceColour);
        
        Move getMove(Board*, bool isWhiteToMove=true) override;
};

#endif
