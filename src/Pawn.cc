#include "Piece.h"
#include "Rook.h"

using namespace std;

vector<vector<pair<int,int>>> Pawn::getMoveDirections() override {
    return {
        {{1,0},{}},
    };
};
