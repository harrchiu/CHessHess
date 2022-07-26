#include <vector>
#include "Piece.h"
#include "King.h"
#include "PotentialMove.h"

using namespace std;

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

    return pMoves;  
};

PieceType King::type() {
    return PieceType::KING;
};

King::King(bool isWhite) : Piece(isWhite) {};
King::~King(){};
