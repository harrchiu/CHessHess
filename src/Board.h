#include <vector>

#include "Move.h"
#include "Square.h"

class Board {
    int rows, cols;
    std::vector<std::vector<Square>> grid;
    public:
        void setup();
        std::vector<Move> playedMoveList;
        std::vector<Move> getValidMoves();
        bool isCheck();
        bool isMate();
        int getRows();
        int getCols();
        std::vector<std::vector<Square>> getBoard(); 
        Board(int, int);
        ~Board();
};
