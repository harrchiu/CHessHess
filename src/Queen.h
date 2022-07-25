#ifndef QUEEN_H
#define QUEEN_H

#include <vector>
#include "Piece.h"
#include "PotentialMove.h"

class Queen : public Piece {
    public:
        std::vector<std::vector<PotentialMove>> getMoveDirections() override;
        PieceType type() override;
        Queen(bool);
        ~Queen() override;
};

#endif
