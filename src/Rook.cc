#include <vector>
#include "Piece.h"
#include "Rook.h"

using namespace std;

vector<vector<pair<int,int>>> Rook::getMoveDirections() {
    return {
        {{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0}},
        {{-1,0},{-2,0},{-3,0},{-4,0},{-5,0},{-6,0},{-7,0}},
        {{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7}},
        {{0,-1},{0,-2},{0,-3},{0,-4},{0,-5},{0,-6},{0,-7}},
    };
};


PieceType Rook::type() {
    return PieceType::Rook;
};