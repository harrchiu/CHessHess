#include <vector>
#include "Piece.h"
#include "Rook.h"
#include "PotentialMove.h"


using namespace std;

vector<vector<PotentialMove>> Rook::getMoveDirections() {
    vector<vector<PotentialMove>> pMoves(4);
    PotentialMoveType pmt = getIsWhite() ? DEST_EMPTY_BLACK : DEST_EMPTY_WHITE;

    for (int i=1;i<=7;++i){
        pMoves[0].push_back(PotentialMove(i,0,pmt));
        pMoves[1].push_back(PotentialMove(-i,0,pmt));
        pMoves[2].push_back(PotentialMove(0,i,pmt));
        pMoves[3].push_back(PotentialMove(0,-i,pmt));
    }

    return pMoves;
    // return {
    //     {{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0}},
    //     {{-1,0},{-2,0},{-3,0},{-4,0},{-5,0},{-6,0},{-7,0}},
    //     {{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7}},
    //     {{0,-1},{0,-2},{0,-3},{0,-4},{0,-5},{0,-6},{0,-7}},
    // };
};


PieceType Rook::type() {
    return PieceType::ROOK;
};

Rook::Rook(bool isWhite) : Piece(isWhite) {};
Rook::~Rook(){};
