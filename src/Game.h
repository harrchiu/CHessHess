#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
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
        std::unique_ptr<Player> players[2];
    public:
        Game(Board* b);
        ~Game();
        
        void setPlayer(PieceColour c,std::unique_ptr<Player> p);
        void init();
        void setup();
        Outcome playGame();
        bool attemptMove(Move m);
        void display(State = State::REGULAR);
};

#endif
