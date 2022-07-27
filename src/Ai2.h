#ifndef AI_2_H
#define AI_2_H

#include "Player.h" 

class Ai2 : public Player {
    public:
        Ai2(PieceColour pair);
        
        Move getMove(Board*, bool isWhiteToMove=true) override;
};

#endif
