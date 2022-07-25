#ifndef KNIGHT_H
#define KNIGHT_H

#include <vector>
#include "Piece.h"
#include "PotentialMove.h"

class Knight : public Piece {
    public:
        std::vector<std::vector<PotentialMove>> getMoveDirections() override;
        PieceType type() override;
        Knight(bool);
        ~Knight() override;
};

#endif
