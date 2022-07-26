#ifndef MOVE_H
#define MOVE_H

#include <utility>
#include <iostream>
#include "Piece.h"

// struct to represent a chess move
struct Move {
    public:
        Move(int,int,int,int, bool isWhiteToMove=true, MoveType moveType=MoveType::NORMAL,
            PieceType=PieceType::EMPTY, PieceType=PieceType::EMPTY, PieceType=PieceType::EMPTY);
        
        std::pair<int,int> start;
        std::pair<int,int> end;
        PieceType piece;
        PieceType capturedPiece;
        bool isSideWhite;
        PieceType promotedTo;   // for pawn-promotion moves
        MoveType moveType;
        
    
    friend std::ostream &operator<<(std::ostream &, const Move &);
};


#endif