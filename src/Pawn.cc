#include <vector>
#include <iostream>
#include <math.h>
#include "Piece.h"
#include "Pawn.h"
#include "PotentialMove.h"

using namespace std;

// getMoveDirections - returns all potential moves a pawn can perform
vector<vector<PotentialMove>> Pawn::getMoveDirections() {

    // "white moves up the board" = smaller row
    int vertDir = getIsWhite() ? -1 : 1;
    bool dWhite = !getIsWhite();
    bool dBlack = getIsWhite();
    MoveType mt = MoveType::NORMAL;

    vector<vector<PotentialMove>> pMoves = {
        {PotentialMove(vertDir, 0,  true,false,false,mt)},
        {PotentialMove(vertDir, -1, false,dWhite,dBlack,mt)},
        {PotentialMove(vertDir, 1,  false,dWhite,dBlack,mt)},

        // promotion
        {PotentialMove(vertDir, 0,  true,false,false,   MoveType::PROMOTION)},
        {PotentialMove(vertDir, -1, false,dWhite,dBlack,MoveType::PROMOTION)},
        {PotentialMove(vertDir, 1,  false,dWhite,dBlack,MoveType::PROMOTION)},

        // en passant
        {PotentialMove(vertDir, -1, true,false,false,MoveType::EN_PASSANT)},
        {PotentialMove(vertDir, 1,  true,false,false,MoveType::EN_PASSANT)},
        
        // double pawn move
        {PotentialMove(vertDir*2, 0, true,false,false,MoveType::DOUBLE_PAWN)}
    };

    return pMoves;
};

// type - returns PAWN type
PieceType Pawn::type() {
    return PieceType::PAWN;
};

//CTOR
Pawn::Pawn(bool isWhite) : Piece(isWhite) {};
//DTOR
Pawn::~Pawn(){};

double Pawn::getPoints(int r,int c) { 
    double score = 1;
    int backRow = getIsWhite() ? 7 : 0;

    // values for how far pawn is from edge
    int colApart = 3.5 - abs(3.5 - c);
    int rowApart = abs(backRow-r);

    // reward center pawns for being pushed first
    // will prioritize moves like e4/e5 instead of pushing wing pawns
    score += pow(1.05, colApart + rowApart);    

    return score * (getIsWhite() ? 1 : -1);
};
