#ifndef POTENTIAL_MOVE_H
#define POTENTIAL_MOVE_H

#include <utility>

// describe the move's requirement
// normally only depends on destination square
enum PotentialMoveType {
    DEST_EMPTY,
    DEST_WHITE,
    DEST_BLACK,
    DEST_EMPTY_BLACK,
    DEST_EMPTY_WHITE,
    // CASTLE_Q_SIDE,
    // CASTLE_K_SIDE,
    // EN_PASSANT,
};

class PotentialMove {
    public:
        int rowMov, colMov;
        PotentialMoveType type;
        PotentialMove(int,int,PotentialMoveType);
};

#endif
