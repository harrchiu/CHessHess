#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <utility>
#include <string>

#include "Move.h"
#include "Square.h"
#include "TextualDisplay.h"
#include "GraphicalDisplay.h"
#include "Piece.h"

//Class to represent the chess board
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
    
    std::vector<std::string> previousFENs;
    public:
        Board(int, int);
        ~Board();
        
        std::vector<Move> playedMoveList = {};
        std::vector<std::vector<Square>>& getBoard(); 
        std::vector<Move> getLegalMoves(bool isWhiteToMove);
        bool isCheck(bool isSideWhite, bool disableCastle = false);
        void setupInitialPosition();

        // move info/application
        void setSquare(int,int,PieceType,bool);
        bool undoLastMove(bool updateDisplay=false); // do nothing if no moves
        void applyMove(Move&,bool updateDisplay=false);
        void display(State);
        void printLegalMoves();

        std::string getFEN();
        bool isThreeFold();
        void handleFENStart();
};

#endif
