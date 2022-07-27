#ifndef BISHOP_H
#define BISHOP_H

#include <vector>
#include "Piece.h"
#include "PotentialMove.h"

//Class to represent Bishop piece
class Bishop : public Piece {
    public:
        Bishop(bool);
        ~Bishop() override;
        
        std::vector<std::vector<PotentialMove>> getMoveDirections() override;
        PieceType type() override;
        double getPoints(int,int) override;
};

#endif
