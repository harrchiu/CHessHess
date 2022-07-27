#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
#include "Piece.h"
#include "Board.h"
#include "Player.h"
#include "Move.h"

//enum on the possible outcomes of the game
enum Outcome { WHITE_VICTORY=0, BLACK_VICTORY=1, TIE=2 };

//class to represent the game of chess
class Game {
        //white is 0,black is 1
        // PieceColour curTurn;
        bool isWhiteToMove;
        Board* board;
        bool attemptMove(Move m);
        std::unique_ptr<Player> players[2];
    public:
        Game(Board* b);
        ~Game();
        
        void init();
        void setup();
        Outcome playGame();
        void setPlayer(PieceColour c,std::unique_ptr<Player> p);
        void display(State = State::REGULAR);
};

#endif
