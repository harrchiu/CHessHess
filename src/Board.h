#include <vector>
#include "move.h"
#include "square.h"

class Board {
    public:
        std::vector<Move> playedMoveList;
        std::vector<Move> getValidMoves();
        bool isCheck();
        bool isMate();
        std::vector<std::vector<Square>> getBoard(); 
};