#ifndef GAME_H
#define GAME_H

#include <string>
#include "Piece.h"
#include "Board.h"
#include "Player.h"
#include "Move.h"

enum Outcome { WHITE_WIN=0, BLACK_WIN=1, STALEMATE=2 };
enum State { WHITE_CHECK=0, BLACK_CHECK=1, WHITE_RESIGN=2, BLACK_RESIGN=3, WHITE_WIN=4, BLACK_WIN=5, STALEMATE=6, REGULAR=7 };

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
        void display(State);
};

#endif
