#ifndef AI_4_H
#define AI_4_H

#include "Player.h" 

class Ai4 : public Player {
    public:
        Ai4(PieceColour p);
        
        Move getMove(Board*) override;
};

#endif
