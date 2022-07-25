#include <vector>
#include "Bishop.h"

using namespace std;

vector<vector<pair<int,int>>> Bishop::getMoveDirections(){
    return {
        {{1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7}},
        {{-1,1},{-2,2},{-3,3},{-4,4},{-5,5},{-6,6},{-7,7}},
        {{1,-1},{2,-2},{3,-3},{4,-4},{5,-5},{6,-6},{7,-7}},
        {{-1,-1},{-2,-2},{-3,-3},{-4,-4},{-5,-5},{-6,-6},{-7,-7}},
    };
};

PieceType Bishop::type() {
    return PieceType::Bishop;
};
