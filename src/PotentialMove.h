#ifndef POTENTIAL_MOVE_H
#define POTENTIAL_MOVE_H

#include <utility>

// describe the move's requirement
// normally only depends on destination square
enum MoveType {
    NORMAL,
    CASTLE_Q_SIDE,
    CASTLE_K_SIDE,
    EN_PASSANT,
    DOUBLE_PAWN,
    PROMOTION,
};

class PotentialMove {
    public:
        int rowMov, colMov;
        bool canDestBeEmpty = false;
        bool canDestBeWhite = false;
        bool canDestBeBlack = false;
        MoveType mt;
        
                    // empty, white, black
                    //     v    v     v
    PotentialMove(int,int,bool,bool,bool,MoveType);
};

#endif
