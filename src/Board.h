#ifndef BOARD
#define BOARD

#include <vector>
#include <utility>

#include "Move.h"
#include "Square.h"

class Board {
    int rows, cols;
    
    public:
        Board(int, int);
        Board(const Board&);    // l-value copy (deep copy)
        ~Board();
        
        void setup();
        std::vector<std::vector<Square>> grid;
        std::vector<Move> playedMoveList;
        std::vector<Move> getMoves(bool isSideWhite);// helper for getLegalMoves
        std::vector<Move> getLegalMoves(bool isSideWhite);
        std::pair<bool,bool> isCheck();  // <white, black>
        std::pair<bool,bool> isMate();  
        std::vector<std::vector<Square>> getBoard(); 

        int getRows();  // getters/helper fn
        int getCols();
        bool isOnBoard(const int, const int);
        void makeMove(Move m, bool isWhiteToMove);
        void applyMove(Move m);
};

#endif