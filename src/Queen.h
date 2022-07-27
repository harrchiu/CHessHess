#ifndef QUEEN_H
#define QUEEN_H

#include <vector>
#include "Piece.h"
#include "PotentialMove.h"

// class to represent a Queen Piece
class Queen : public Piece {
    public:
        Queen(bool);
        ~Queen() override;
        
        std::vector<std::vector<PotentialMove>> getMoveDirections() override;
        PieceType type() override;
        double getPoints(int,int) override;
};

#endif
