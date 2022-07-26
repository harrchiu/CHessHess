#ifndef GAME_H
#define GAME_H

#include <string>
#include "Piece.h"
#include "Board.h"
#include "Player.h"
#include "Move.h"

enum Outcome { WHITE_VICTORY=0, BLACK_VICTORY=1, TIE=2 };

class Game {
        //white is 0,black is 1
        // PieceColour curTurn;
        bool isWhiteToMove;
        Board* board;
        Player* players[2];
        bool attemptMove(Move m);
    public:
        Game(Board* b);
        ~Game();
        
        void init();
        void setup();
        Outcome playGame();
        void setPlayer(PieceColour c,Player* p);
        void display(State = State::REGULAR);
};

#endif
