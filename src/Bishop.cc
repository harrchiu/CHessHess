#include <vector>
#include "Piece.h"
#include "Bishop.h"
#include "PotentialMove.h"

using namespace std;

vector<vector<PotentialMove>> Bishop::getMoveDirections(){
    vector<vector<PotentialMove>> pMoves(4);
    MoveType mt = getIsWhite() ? DEST_EMPTY_BLACK : DEST_EMPTY_WHITE;

    for (int i=1;i<=7;++i){
        pMoves[0].push_back(PotentialMove(i,i,mt));
        pMoves[1].push_back(PotentialMove(-i,i,mt));
        pMoves[2].push_back(PotentialMove(i,-i,mt));
        pMoves[3].push_back(PotentialMove(-i,-i,mt));
    }

    return pMoves;
    // return {
    //     {{1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7}},
    //     {{-1,1},{-2,2},{-3,3},{-4,4},{-5,5},{-6,6},{-7,7}},
    //     {{1,-1},{2,-2},{3,-3},{4,-4},{5,-5},{6,-6},{7,-7}},
    //     {{-1,-1},{-2,-2},{-3,-3},{-4,-4},{-5,-5},{-6,-6},{-7,-7}},
    // };
};

PieceType Bishop::type() {
    return PieceType::BISHOP;
};

Bishop::Bishop(bool isWhite) : Piece(isWhite) {};
Bishop::~Bishop(){};
