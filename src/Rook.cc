#include <vector>
#include "Piece.h"
#include "Rook.h"
#include "PotentialMove.h"

using namespace std;

// getMoveDirections - returns all potential moves a queen can perform
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
};

// type - returns type ROOK
PieceType Rook::type() {
    return PieceType::ROOK;
};

// CTOR
Rook::Rook(bool isWhite) : Piece(isWhite) {};
// DTOR
Rook::~Rook(){};
