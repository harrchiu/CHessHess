#ifndef GAME_H
#define GAME_H

#include <string>
#include "Piece.h"
#include "Board.h"
#include "Player.h"
#include "Move.h"

class Game {
        //white is 0,black is 1
        // PieceColour curTurn;
        bool isWhiteToMove;
        Board *board;
        Player* players[2];
    public:
        void setPlayer(PieceColour c,Player* p);
        void init();
        void setup();
        std::string playGame();
        void makeMove(Move m);
        Game(Board* b);
        ~Game();
};

#endif
