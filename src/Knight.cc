#include <vector>
#include "Piece.h"
#include "Knight.h"
#include "PotentialMove.h"

using namespace std;

vector<vector<PotentialMove>> Knight::getMoveDirections() {
    vector<pair<int,int>> knight_disp = {{1,2},{-1,2},{1,-2},{-1,-2},
        {2,1},{-2,1},{2,-1},{-2,-1}};

    vector<vector<PotentialMove>> pMoves;
    PotentialMoveType pmt = getIsWhite() ? DEST_EMPTY_BLACK : DEST_EMPTY_WHITE;

    for (auto disp : knight_disp){
        pMoves.push_back({PotentialMove(disp.first,disp.second,pmt)});
    }

    return pMoves;  
};

PieceType Knight::type() {
    return PieceType::KNIGHT;
};

Knight::Knight(bool isWhite) : Piece(isWhite) {};
Knight::~Knight(){};
