#ifndef QUEEN
#define QUEEN

#include <vector>
#include "Piece.h"
#include "PotentialMove.h"

class Queen : public Piece {
    std::vector<std::vector<PotentialMove>> getMoveDirections() override;
    virtual PieceType type();
    Queen(bool);
    ~Queen() override;
};

#endif
