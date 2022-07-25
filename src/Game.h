#include <string>
#include "Piece.h"
#include "Board.h"

class Game {
        //white is 0,black is 1
        PieceColour curTurn;
        Board board;
    public:
        void init();
        void setup();
        string playGame();
};
