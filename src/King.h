#ifndef KING_H
#define KING_H

#include <vector>
#include "Piece.h"
#include "PotentialMove.h"

// class to represent a King Piece
class King : public Piece {
    public:
        King(bool);
        ~King() override;
        
        std::vector<std::vector<PotentialMove>> getMoveDirections() override;
        PieceType type() override;
        double getPoints(int,int) override;
};

#endif
