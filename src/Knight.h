#ifndef KNIGHT_H
#define KNIGHT_H

#include <vector>
#include "Piece.h"
#include "PotentialMove.h"

class Knight : public Piece {
    public:
        Knight(bool);
        ~Knight() override;
        
        std::vector<std::vector<PotentialMove>> getMoveDirections() override;
        PieceType type() override;
        double getPoints(int,int) override;
};

#endif
