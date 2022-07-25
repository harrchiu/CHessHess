#include "Bishop.h"

using namespace std;

vector<vector<pair<int,int>>> Bishop::getMoveDirections() override {
    return {
        {{1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7}},
        {{-1,1},{-2,2},{-3,3},{-4,4},{-5,5},{-6,6},{-7,7}},
        {{1,-1},{2,-2},{3,-3},{4,-4},{5,-5},{6,-6},{7,-7}},
        {{-1,-1},{-2,-2},{-3,-3},{-4,-4},{-5,-5},{-6,-6},{-7,-7}},
    };
};


// vector<vector<pair<int,int>>> ret = {{},{},{},{}};

// for (int i=1;i<=7;++i){
//     ret[0].push_back({i,i});
//     ret[1].push_back({-i,i});
//     ret[2].push_back({i,-i});
//     ret[3].push_back({-i,-i});
// }
// return ret;
