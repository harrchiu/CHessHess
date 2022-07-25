#ifndef BISHOP_H
#define BISHOP_H

#include <vector>
#include "Piece.h"
#include "PotentialMove.h"

class Bishop : public Piece {
    public:
        std::vector<std::vector<PotentialMove>> getMoveDirections() override;
        PieceType type() override;
        Bishop(bool);
        ~Bishop() override;
};

#endif
