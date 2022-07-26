#ifndef POTENTIAL_MOVE_H
#define POTENTIAL_MOVE_H

#include <utility>
#include "PotentialMoveInfo.h"

// describe the move's requirement
// normally only depends on destination square
enum MoveType {
    CASTLE_Q_SIDE,
    CASTLE_K_SIDE,
    EN_PASSANT,
    DOUBLE_PAWN,
    PROMOTION,
};

class PotentialMove {
    public:
        int rowMov, colMov;
        PotentialMoveInfo pmi;
        PotentialMove(int,int,PotentialMoveInfo);
};

#endif
