#ifndef MOVE_H
#define MOVE_H

#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include "Move.h"
#include "Piece.h"


class Move {
    public:
        std::pair<int,int> start;
        std::pair<int,int> end;
        bool isSideWhite;
        PieceType piece;
        PieceType capturedPiece;

        PieceType promotedTo;   // for pawn-promotion moves
        MoveType moveType;
        
        std::string getAlgNotation(const std::vector<Move>& otherMoves={}) const;
        
        Move(int,int,int,int, bool isWhiteToMove=true, MoveType moveType=MoveType::NORMAL,
            PieceType=PieceType::EMPTY, PieceType=PieceType::EMPTY, PieceType=PieceType::EMPTY);
    
    friend std::ostream &operator<<(std::ostream &, const Move &);
};


#endif