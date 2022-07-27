#ifndef AI_2_H
#define AI_2_H

#include "Player.h" 

// Class to represent Ai - level 2
class Ai2 : public Player {
    public:
        Ai2(PieceColour pair);
        
        Move getMove(Board*, bool isWhiteToMove=true) override;
};

#endif
