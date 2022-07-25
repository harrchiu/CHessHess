#ifndef AI_2_H
#define AI_2_H

#include "Player.h" 

class Ai2 : public Player {
    public:
        Move getMove(Board*) override;
};

#endif
