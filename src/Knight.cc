#include <vector>
#include "Knight.h"

using namespace std;

vector<vector<pair<int,int>>> Knight::getMoveDirections() {
    return {
        {{1,2}},
        {{-1,2}},
        {{1,-2}},
        {{-1,-2}},
        {{2,1}},
        {{-2,1}},
        {{2,-1}},
        {{-2,-1}}
    };
};

PieceType Knight::type() {
    return PieceType::Knight;
};