#include <vector>
#include "Piece.h"

class King : public Piece {
    std::vector<std::vector<std::pair<int,int>>> getMoveDirections() override;
};
