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
        // Board(const Board&);    // l-value copy (deep copy)
        ~Board();
        
        void setup();
        std::vector<std::vector<Square>> grid;
        std::vector<Move> playedMoveList = {};
        std::vector<Move> getLegalMoves(bool isWhiteToMove);
        bool isCheck(bool isSideWhite, bool disableCastle=false);
        bool isMate(bool isSideWhite);  
        std::vector<std::vector<Square>>& getBoard(); 
        void setupInitialPosition(); 

        // getters/helper fns
        int getRows();  
        int getCols();
        bool isOnBoard(const int, const int);
        std::vector<Move> getMoves(bool isWhiteToMove,bool disableCastle=false);
        std::pair<int,int> getKingCoords(bool);
        bool canReach(bool, int, int, bool disableCastle=false);
        bool hasSquareBeenTouched(int, int);

        // move info/application
        void setSquare(int,int,PieceType,bool);

        void applyMove(Move&,bool updateDisplay=false);
        bool undoLastMove(bool updateDisplay=false); // do nothing if no moves
        void printLegalMoves();
        void display(State);
};

#endif