#ifndef POTENTIAL_MOVE_H
#define POTENTIAL_MOVE_H

#include <utility>


//enum for the types of moves
enum MoveType {
    NORMAL,
    CASTLE_Q_SIDE,
    CASTLE_K_SIDE,
    EN_PASSANT,
    DOUBLE_PAWN,
    PROMOTION,
};

// class to represent the potential things a chess piece can do.
// describe the move's requirement ( if destination must be an empty square,
// black piece or white piece etc.) and its type
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
