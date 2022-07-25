#include <vector>

#include "Move.h"
#include "Square.h"

class Board {
    int rows, cols;
    std::vector<std::vector<Square>> grid;
    
    public:
        Board(int, int);
        Board(const Board&);    // l-value copy (deep copy)
        ~Board();
        
        void setup();
        std::vector<Move> playedMoveList;
        std::vector<Move> getMoves(bool isSideWhite);// helper for getLegalMoves
        std::vector<Move> getLegalMoves(bool isSideWhite);
        pair<bool,bool> isCheck();  // <white, black>
        pair<bool,bool> isMate();  
        std::vector<std::vector<Square>> getBoard(); 

        int getRows();  // getters/helper fn
        int getCols();
        bool isOnBoard(const int, const int);
};
