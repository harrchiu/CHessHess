#ifndef MOVE_H
#define MOVE_H

#include <utility>
#include <iostream>
#include "Piece.h"

struct Move {
    public:
        std::pair<int,int> start;
        std::pair<int,int> end;
        bool isSideWhite;
        PieceType piece;
        PieceType capturedPiece;

        PieceType promotedTo;   // for pawn-promotion moves
        MoveType moveType;
        
        Move(int,int,int,int, bool isWhiteToMove=true, MoveType moveType=MoveType::NORMAL,
            PieceType=PieceType::EMPTY, PieceType=PieceType::EMPTY, PieceType=PieceType::EMPTY);
    
    friend std::ostream &operator<<(std::ostream &, const Move &);
};


#endif