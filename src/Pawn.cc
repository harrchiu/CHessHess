#include <vector>
#include "Piece.h"
#include "Pawn.h"
#include "PotentialMove.h"

using namespace std;

vector<vector<PotentialMove>> Pawn::getMoveDirections() {
    // "white moves up the board" = smaller row
    int verticalDir = getIsWhite() ? -1 : 1;
    bool dWhite = !getIsWhite();
    bool dBlack = getIsWhite();
    MoveType mt = MoveType::NORMAL;

    vector<vector<PotentialMove>> pMoves = {
        {PotentialMove(verticalDir, 0,  true,false,false,mt)},
        {PotentialMove(verticalDir, -1, false,dWhite,dBlack,mt)},
        {PotentialMove(verticalDir, 1,  false,dWhite,dBlack,mt)}
    };

    return pMoves;
};

PieceType Pawn::type() {
    return PieceType::PAWN;
};

Pawn::Pawn(bool isWhite) : Piece(isWhite) {};
Pawn::~Pawn(){};

