#ifndef AI_3_H
#define AI_3_H

#include "Player.h" 

class Ai3 : public Player {
    public:
        Ai3(PieceColour p);
        
        Move getMove(Board*) override;
        signed int checkBoardScore(Board*);
        signed int checkMostDetrimentalResponseScore(Board*);
};

#endif