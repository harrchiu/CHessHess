#include <vector>
#include "King.h"

using namespace std;

vector<vector<pair<int,int>>> King::getMoveDirections() {
    return {
        {{1,0}},
        {{-1,0}},
        {{0,1}},
        {{0,-1}},
        {{1,1}},
        {{-1,1}},
        {{1,-1}},
        {{-1,-1}}
    };
};
