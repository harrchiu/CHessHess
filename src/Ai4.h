#ifndef AI_4_H
#define AI_4_H

#include "Player.h" 

// Class to represent Ai - level 4
class Ai4 : public Player {
    public:
        Ai4(PieceColour p);
        
        Move getMove(Board*, bool isWhiteToMove) override;
};

#endif
