#ifndef BISHOP
#define BISHOP

#include <vector>
#include "Piece.h"
#include "PotentialMove.h"

class Bishop : public Piece {
    std::vector<std::vector<PotentialMove>> getMoveDirections() override;
    virtual PieceType type();
    Bishop(bool);
    ~Bishop() override;
};

#endif
