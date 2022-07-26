#ifndef AI_1_H
#define AI_1_H

#include "Player.h" 

class Ai1 : public Player {
    public:
        Move getMove(Board*) override;
        Ai1(PieceColour);
};

#endif