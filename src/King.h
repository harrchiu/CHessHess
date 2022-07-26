#ifndef KING_H
#define KING_H

#include <vector>
#include "Piece.h"
#include "PotentialMove.h"

class King : public Piece {
    public:
        King(bool);
        ~King() override;
        
        std::vector<std::vector<PotentialMove>> getMoveDirections() override;
        PieceType type() override;
};

#endif
