#ifndef KNIGHT
#define KNIGHT

#include "Piece.h"

class Knight : public Piece {
    std::vector<std::vector<std::pair<int,int>>> getMoveDirections() override;
    virtual PieceType type();
};

#endif