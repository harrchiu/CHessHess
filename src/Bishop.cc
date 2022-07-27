#include <vector>
#include "Piece.h"
#include "Bishop.h"
#include "PotentialMove.h"

using namespace std;

// getMoveDirections - returns all potential moves a bishop piece can perform
vector<vector<PotentialMove>> Bishop::getMoveDirections(){
    vector<vector<PotentialMove>> pMoves(4);
    
    // If the piece is one colour, the destination square can be a piece
    // from the other colour but not the pieces colour.
    bool dEmpty = true;
    bool dWhite = !getIsWhite();
    bool dBlack = getIsWhite();
    MoveType mt = MoveType::NORMAL;

    // add a potential move for every square in every diagonal direction
    for (int i=1;i<=7;++i){
         // bishop
        pMoves[0].push_back(PotentialMove(i,i,  dEmpty,dWhite,dBlack,mt));
        pMoves[1].push_back(PotentialMove(-i,i, dEmpty,dWhite,dBlack,mt));
        pMoves[2].push_back(PotentialMove(i,-i, dEmpty,dWhite,dBlack,mt));
        pMoves[3].push_back(PotentialMove(-i,-i,dEmpty,dWhite,dBlack,mt));
    }

    return pMoves;
};

// type - returns the BISHOP type
PieceType Bishop::type() {
    return PieceType::BISHOP;
};

//CTOR
Bishop::Bishop(bool isWhite) : Piece(isWhite) {};
//DTOR
Bishop::~Bishop(){};
