#include <vector>
#include "Piece.h"
#include "Queen.h"
#include "PotentialMove.h"

using namespace std;

// getMoveDirections - returns all potential moves a queen can perform
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
};

// type - returns type QUEEN
PieceType Queen::type() {
    return PieceType::QUEEN;
};

// CTOR
Queen::Queen(bool isWhite) : Piece(isWhite) {};
// DTOR
Queen::~Queen(){};
