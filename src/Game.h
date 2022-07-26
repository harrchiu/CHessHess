#ifndef GAME_H
#define GAME_H

#include <string>
#include "Piece.h"
#include "Board.h"
#include "Player.h"
#include "Move.h"

enum Outcome { WHITE_RESIGN=0, BLACK_RESIGN=1, WHITE_WIN=2, BLACK_WIN=3, STALEMATE=4 };

class Game {
        //white is 0,black is 1
        // PieceColour curTurn;
        bool isWhiteToMove;
        Board *board;
        Player* players[2];
    public:
        Game(Board* b);
        ~Game();
        
        void setPlayer(PieceColour c,Player* p);
        void init();
        void setup();
        Outcome playGame();
        bool attemptMove(Move m);
        void display();
};

#endif
