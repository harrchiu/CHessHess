#ifndef GAME
#define GAME

#include <string>
#include "Piece.h"
#include "Board.h"
#include "Player.h"
#include "Move.h"

class Game {
        //white is 0,black is 1
        // PieceColour curTurn;
        bool isWhiteToMove;
        Board board;
        Player players[2];
    public:
        void setPlayer(PieceColour c,Player p);
        Game(Board b);
        void init();
        void setup();
        string playGame();
        void makeMove(Move m);
};

#endif