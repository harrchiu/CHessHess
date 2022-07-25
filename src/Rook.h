#ifndef ROOK_H
#define ROOK_H

#include <vector>
#include "Piece.h"
#include "PotentialMove.h"


class Rook : public Piece {
    public:
        std::vector<std::vector<PotentialMove>> getMoveDirections() override;
        PieceType type() override;
        Rook(bool);
        ~Rook() override;
};

#endif
