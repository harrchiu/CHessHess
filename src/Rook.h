#ifndef ROOK
#define ROOK

#include <vector>
#include "Piece.h"
#include "PotentialMove.h"


class Rook : public Piece {
    std::vector<std::vector<PotentialMove>> getMoveDirections() override;
    virtual PieceType type();
    Rook(bool);
    ~Rook() override;
};

#endif
