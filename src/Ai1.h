#ifndef AI_1_H
#define AI_1_H

#include "Player.h" 

// Class to represent Ai - level 1
class Ai1 : public Player {
    public:
        Ai1(PieceColour);
        
        Move getMove(Board*) override;
};

#endif