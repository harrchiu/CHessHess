#include <vector>
#include "Piece.h"

class Queen : public Piece {
    std::vector<std::vector<std::pair<int,int>>> getMoveDirections() override;
    virtual PieceType type();
};
