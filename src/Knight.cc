#include <vector>
#include "math.h"
#include "Piece.h"
#include "Knight.h"
#include "PotentialMove.h"

using namespace std;

vector<vector<PotentialMove>> Knight::getMoveDirections() {
    vector<pair<int,int>> knight_disp = { {1,2},{-1,2},{1,-2},{-1,-2},
        {2,1},{-2,1},{2,-1},{-2,-1} };

    vector<vector<PotentialMove>> pMoves;
    bool dEmpty = true;
    bool dWhite = !getIsWhite();
    bool dBlack = getIsWhite();
    MoveType mt = MoveType::NORMAL;

    for (auto disp : knight_disp){
        pMoves.push_back({PotentialMove(disp.first,disp.second,
            dEmpty,dWhite,dBlack,mt)});
    }

    return pMoves;  
};

PieceType Knight::type() {
    return PieceType::KNIGHT;
};

Knight::Knight(bool isWhite) : Piece(isWhite) {};
Knight::~Knight(){};

double Knight::getPoints(int r,int c) { 
    double score = 3;
    int backRow = getIsWhite() ? 7 : 0;

    int colApart = 3.5 - abs(3.5 - c);
    int rowApart = abs(backRow-r);

    score += pow(1.03, colApart + rowApart);
    return score * (getIsWhite() ? 1 : -1);
};
