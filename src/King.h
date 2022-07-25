#ifndef KING_H
#define KING_H

#include <vector>
#include "Piece.h"
#include "PotentialMove.h"

class King : public Piece {
    public:
        std::vector<std::vector<PotentialMove>> getMoveDirections() override;
        PieceType type() override;
        King(bool);
        ~King() override;
};

#endif
