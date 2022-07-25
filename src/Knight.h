#ifndef KNIGHT
#define KNIGHT

#include <vector>
#include "Piece.h"
#include "PotentialMove.h"

class Knight : public Piece {
    std::vector<std::vector<PotentialMove>> getMoveDirections() override;
    virtual PieceType type();
    Knight(bool);
    ~Knight() override;
};

#endif
