#ifndef GAME_H
#define GAME_H

#include <string>
#include "Piece.h"
#include "Board.h"

class Game {
        //white is 0,black is 1
        PieceColour curTurn;
    public:
        Board board;
        void init();
        void setup();
        std::string playGame();
        Game(Board& b);
        ~Game();
};

#endif
