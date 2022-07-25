#ifndef PAWN_H
#define PAWN_H

#include <vector>
#include "Piece.h"
#include "PotentialMove.h"

class Pawn : public Piece {
    public: 
        std::vector<std::vector<PotentialMove>> getMoveDirections() override;
        PieceType type() override;
        Pawn(bool);
        ~Pawn() override;
};

#endif

