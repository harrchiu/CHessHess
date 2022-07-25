#include "Piece.h"

class Bishop : public Piece {
    std::vector<std::vector<std::pair<int,int>>> getMoveDirections() override;
    virtual PieceType type();
};
