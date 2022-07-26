#include <vector>
#include "Piece.h"
#include "Pawn.h"
#include "PotentialMove.h"

using namespace std;

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

        // en passant
        // {PotentialMove(vertDir, -1, true,false,false,MoveType::EN_PASSANT)},
        // {PotentialMove(vertDir, 1,  true,false,false,MoveType::EN_PASSANT)},
        // double pawn move
        {PotentialMove(vertDir*2, 0, true,false,false,MoveType::DOUBLE_PAWN)}
    };

    return pMoves;
};

PieceType Pawn::type() {
    return PieceType::PAWN;
};

Pawn::Pawn(bool isWhite) : Piece(isWhite) {};
Pawn::~Pawn(){};

