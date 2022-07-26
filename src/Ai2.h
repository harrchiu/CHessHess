#ifndef AI_2_H
#define AI_2_H

#include "Player.h" 

class Ai2 : public Player {
    public:
        Ai2(PieceColour p);
        Move getMove(Board*) override;
};

#endif
