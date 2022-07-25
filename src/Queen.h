#include "Piece.h"

class Queen : public Piece {
    std::vector<std::vector<std::pair<int,int>>> getMoveDirections() override;
};
