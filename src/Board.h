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
    std::vector<std::vector<Square>> grid;
    std::vector<Move> getMoves(bool isWhiteToMove,bool disableCastle=false);
    bool isOnBoard(const int, const int);
    std::pair<int,int> getKingCoords(bool);
    bool canReach(bool, int, int, bool disableCastle=false);
    bool hasSquareBeenTouched(int, int);
    
    public:
        Board(int, int);
        // Board(const Board&);    // l-value copy (deep copy)
        ~Board();
        
        void setup();
        std::vector<Move> playedMoveList = {};
        std::vector<Move> getLegalMoves(bool isWhiteToMove);
        std::vector<std::vector<Square>>& getBoard(); 
        void setupInitialPosition(); 

        bool isCheck(bool isSideWhite, bool disableCastle = false);
        // move info/application
        void setSquare(int,int,PieceType,bool);
        void applyMove(Move&,bool updateDisplay=false);
        bool undoLastMove(bool updateDisplay=false); // do nothing if no moves
        void printLegalMoves();
        void display(State);
        
};

#endif