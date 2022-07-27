#ifndef PAWN_H
#define PAWN_H

#include <vector>
#include "Piece.h"
#include "PotentialMove.h"

class Pawn : public Piece {
    public: 
        Pawn(bool);
        ~Pawn() override;
        
        std::vector<std::vector<PotentialMove>> getMoveDirections() override;
        PieceType type() override;
        double getPoints(int,int) override;
};

#endif

