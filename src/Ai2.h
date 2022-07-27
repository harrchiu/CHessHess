#ifndef AI_2_H
#define AI_2_H

#include "Player.h" 

// Class to represent Ai - level 2
class Ai2 : public Player {
    public:
        Ai2(PieceColour p);
        
        Move getMove(Board*) override;
};

#endif
