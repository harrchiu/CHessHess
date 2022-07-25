#ifndef AI_3_H
#define AI_3_H

#include "Player.h" 

class Ai3 : public Player {
    public:
        Move getMove(Board*) override;
};

#endif