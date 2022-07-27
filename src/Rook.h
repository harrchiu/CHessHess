#ifndef ROOK_H
#define ROOK_H

#include <vector>
#include "Piece.h"
#include "PotentialMove.h"

// class to represent a Rook Piece
class Rook : public Piece {
    public:
        Rook(bool);
        ~Rook() override;
        
        std::vector<std::vector<PotentialMove>> getMoveDirections() override;
        PieceType type() override;
        double getPoints(int,int) override;
};

#endif
