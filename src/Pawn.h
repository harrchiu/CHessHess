#ifndef PAWN_H
#define PAWN_H

#include <vector>
#include "Piece.h"
#include "PotentialMove.h"

// class to represent a Pawn Piece
class Pawn : public Piece {
    public: 
        Pawn(bool);
        ~Pawn() override;
        
        std::vector<std::vector<PotentialMove>> getMoveDirections() override;
        PieceType type() override;
};

#endif

