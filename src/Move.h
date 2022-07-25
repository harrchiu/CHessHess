#ifndef MOVE_H
#define MOVE_H

#include <utility>
#include "Piece.h"

struct Move {
    public:
        std::pair<int,int> start;
        std::pair<int,int> end;
        PieceType piece;
        PieceType capturedPiece;

        PieceType promotedTo;   // for pawn-promotion moves

        Move(int,int,int,int,PieceType=PieceType::EMPTY,
            PieceType=PieceType::EMPTY, PieceType=PieceType::EMPTY);
};

#endif