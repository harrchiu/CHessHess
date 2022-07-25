#include <vector>
#include "Piece.h"
#include "Queen.h"
#include "PotentialMove.h"

using namespace std;

vector<vector<PotentialMove>> Queen::getMoveDirections() {
    vector<vector<PotentialMove>> pMoves(8);
    PotentialMoveType pmt = getIsWhite() ? DEST_EMPTY_BLACK : DEST_EMPTY_WHITE;

    for (int i=1;i<=7;++i){
        // bishop
        pMoves[0].push_back(PotentialMove(i,i,pmt));
        pMoves[1].push_back(PotentialMove(-i,i,pmt));
        pMoves[2].push_back(PotentialMove(i,-i,pmt));
        pMoves[3].push_back(PotentialMove(-i,-i,pmt));

        // rook
        pMoves[4].push_back(PotentialMove(0,-i,pmt));
        pMoves[5].push_back(PotentialMove(0,-i,pmt));
        pMoves[6].push_back(PotentialMove(0,-i,pmt));
        pMoves[7].push_back(PotentialMove(0,-i,pmt));
    }

    return pMoves;
    // return {
    //     // bishop
    //     {{1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7}},
    //     {{-1,1},{-2,2},{-3,3},{-4,4},{-5,5},{-6,6},{-7,7}},
    //     {{1,-1},{2,-2},{3,-3},{4,-4},{5,-5},{6,-6},{7,-7}},
    //     {{-1,-1},{-2,-2},{-3,-3},{-4,-4},{-5,-5},{-6,-6},{-7,-7}},

    //     // rook
    //     {{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0}},
    //     {{-1,0},{-2,0},{-3,0},{-4,0},{-5,0},{-6,0},{-7,0}},
    //     {{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7}},
    //     {{0,-1},{0,-2},{0,-3},{0,-4},{0,-5},{0,-6},{0,-7}},
    // };
};

PieceType Queen::type() {
    return PieceType::QUEEN;
};

Queen::Queen(bool isWhite) : Piece(isWhite) {};
Queen::~Queen(){};
