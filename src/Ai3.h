#ifndef AI_3_H
#define AI_3_H

#include "Player.h" 

class Ai3 : public Player {
    signed int checkBoardScore(Board*);
    signed int checkMostDetrimentalResponseScore(Board*);
    public:
        Ai3(PieceColour p);        
        Move getMove(Board*, bool isWhiteToMove=true) override;
};

#endif