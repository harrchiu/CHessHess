#include <vector>
#include 'move.h'
#include 'square'

class Board {
    public:
        vector<Move> playedMoveList;
        vector<Move> getValidMoves();
        boolean isCheck();
        boolean isMate();
        vector<vector<Square> getBoard(); 
};