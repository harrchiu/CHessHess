#include <vector>
#include "Piece.h"
#include "Knight.h"
#include "PotentialMove.h"

using namespace std;

// getMoveDirections - gets all potential moves a Knight can perform
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

// type - returns KNIGHT type
PieceType Knight::type() {
    return PieceType::KNIGHT;
};

Knight::Knight(bool isWhite) : Piece(isWhite) {};
Knight::~Knight(){};
