#include "Knight.h"

using namespace std;

vector<vector<pair<int,int>>> Knight::getMoveDirections() override {
    return {
        {{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}}
    };
};
