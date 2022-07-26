#include <vector>
#include "Piece.h"
#include "Pawn.h"
#include "PotentialMove.h"

using namespace std;

vector<vector<PotentialMove>> Pawn::getMoveDirections() {
    // "white moves up the board" = smaller row
    int verticalDir = getIsWhite() ? -1 : 1;
    MoveType mt_opposite = getIsWhite() ? DEST_BLACK : DEST_WHITE;

    vector<vector<PotentialMove>> pMoves = {
        {PotentialMove(verticalDir, 0, DEST_EMPTY)},
        {PotentialMove(verticalDir, -1, mt_opposite)},
        {PotentialMove(verticalDir, 1, mt_opposite)}
    };

    return pMoves;
};

/*
   if (isWhite) {  
        return {
            {{-1,0}},
            {{-1,-1}},
            {{-1,1}}
        };
    }
    else{      
        return {
            {{1,0}},
            {{1,-1}},
            {{1,1}}
        };
    }
*/

PieceType Pawn::type() {
    return PieceType::PAWN;
};

Pawn::Pawn(bool isWhite) : Piece(isWhite) {};
Pawn::~Pawn(){};
