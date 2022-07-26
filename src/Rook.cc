#include <vector>
#include "Piece.h"
#include "Rook.h"
#include "PotentialMove.h"

using namespace std;

vector<vector<PotentialMove>> Rook::getMoveDirections() {
    vector<vector<PotentialMove>> pMoves(4);
    bool dEmpty = true;
    bool dWhite = !getIsWhite();
    bool dBlack = getIsWhite();
    MoveType mt = MoveType::NORMAL;

    for (int i=1;i<=7;++i){
        pMoves[0].push_back(PotentialMove(0,i,  dEmpty,dWhite,dBlack,mt));
        pMoves[1].push_back(PotentialMove(0,-i, dEmpty,dWhite,dBlack,mt));
        pMoves[2].push_back(PotentialMove(i,0,  dEmpty,dWhite,dBlack,mt));
        pMoves[3].push_back(PotentialMove(-i,0, dEmpty,dWhite,dBlack,mt));
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
