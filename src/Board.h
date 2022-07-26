#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <utility>

#include "Move.h"
#include "Square.h"
#include "TextualDisplay.h"
#include "GraphicalDisplay.h"
#include "Piece.h"

class Board {
    int rows, cols;
    TextualDisplay td;
    GraphicalDisplay gd;
    
    public:
        Board(int, int);
        Board(const Board&);    // l-value copy (deep copy)
        ~Board();
        
        void setup();
        std::vector<std::vector<Square>> grid;
        std::vector<Move> playedMoveList;
        std::vector<Move> getMoves(bool isWhiteToMove);// helper for getLegalMoves
        std::vector<Move> getLegalMoves(bool isWhiteToMove);
        bool isCheck(bool isSideWhite);
        bool isMate(bool isSideWhite);  
        std::vector<std::vector<Square>>& getBoard(); 
        void setupInitialPosition(); 

        int getRows();  // getters/helper fn
        int getCols();
        bool isOnBoard(const int, const int);

        void setSquare(int,int,PieceType,bool);

        void applyMove(Move&,bool updateDisplay=false);
        void undoLastMove();  // do nothing if no moves have been played
        void printLegalMoves();
        void display(State);
};

#endif