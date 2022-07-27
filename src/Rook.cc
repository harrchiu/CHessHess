#include <vector>
#include <math.h>
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

double Rook::getPoints(int r,int c) { 
    double score = 5;
    int backRow = getIsWhite() ? 7 : 0;

    // how far is rook from edge of board
    int colApart = 3.5 - abs(3.5 - c);
    int rowApart = abs(backRow-r);

    // prioritize central rooks
    score += pow(1.03, colApart + rowApart);
    return score * (getIsWhite() ? 1 : -1);
};
