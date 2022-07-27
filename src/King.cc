#include <vector>
#include <math.h>
#include "Piece.h"
#include "King.h"
#include "PotentialMove.h"

using namespace std;

// getMoveDirections - gets all potential moves a king can perform
vector<vector<PotentialMove>> King::getMoveDirections() {
    vector<pair<int,int>> king_disp = { {1,0},{-1,0},{0,1},{0,-1},
        {1,1},{-1,1},{1,-1},{-1,-1} };

    vector<vector<PotentialMove>> pMoves;
    bool dEmpty = true;
    bool dWhite = !getIsWhite();
    bool dBlack = getIsWhite();
    MoveType mt = MoveType::NORMAL;

    for (auto disp : king_disp){
        pMoves.push_back({PotentialMove(disp.first,disp.second,
            dEmpty,dWhite,dBlack,mt)});
    }

    pMoves.push_back({PotentialMove(0,2,true,false,false,
        MoveType::CASTLE_K_SIDE)});
    pMoves.push_back({PotentialMove(0,-2,true,false,false,
        MoveType::CASTLE_Q_SIDE)});

    return pMoves;  
};

// type - returns KING type
PieceType King::type() {
    return PieceType::KING;
};

King::King(bool isWhite) : Piece(isWhite) {};
King::~King(){};

double King::getPoints(int r,int c) { 
    double score = 9000;
    score += abs(r - 3.5);    // away from centre
    score += abs(c - 3.5);

    return score * (getIsWhite() ? 1 : -1);
};
