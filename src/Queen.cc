#include <vector>
#include "Piece.h"
#include "math.h"
#include "Queen.h"
#include "PotentialMove.h"

using namespace std;

vector<vector<PotentialMove>> Queen::getMoveDirections() {
    vector<vector<PotentialMove>> pMoves(8);
    
    bool dEmpty = true;
    bool dWhite = !getIsWhite();
    bool dBlack = getIsWhite();
    MoveType mt = MoveType::NORMAL;

    for (int i=1;i<=7;++i){
        // bishop
        pMoves[0].push_back(PotentialMove(i,i,  dEmpty,dWhite,dBlack,mt));
        pMoves[1].push_back(PotentialMove(-i,i, dEmpty,dWhite,dBlack,mt));
        pMoves[2].push_back(PotentialMove(i,-i, dEmpty,dWhite,dBlack,mt));
        pMoves[3].push_back(PotentialMove(-i,-i,dEmpty,dWhite,dBlack,mt));

        // rook
        pMoves[4].push_back(PotentialMove(0,i,  dEmpty,dWhite,dBlack,mt));
        pMoves[5].push_back(PotentialMove(0,-i, dEmpty,dWhite,dBlack,mt));
        pMoves[6].push_back(PotentialMove(i,0,  dEmpty,dWhite,dBlack,mt));
        pMoves[7].push_back(PotentialMove(-i,0, dEmpty,dWhite,dBlack,mt));
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

double Queen::getPoints(int r,int c) { 
    double score = 9.3;
    int backRow = getIsWhite() ? 7 : 0;

    int colApart = 3.5 - abs(3.5 - c);
    int rowApart = abs(backRow-r);

    score += pow(1.03, colApart + rowApart);
    return score * (getIsWhite() ? 1 : -1);
};
