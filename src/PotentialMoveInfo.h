// #include "PotentialMove.h"
#ifndef POTENTIAL_MOVE_INFO_H
#define POTENTIAL_MOVE_INFO_H

class PotentialMoveInfo {
    public:
        bool canDestBeEmpty = false;
        bool canDestBeWhite = false;
        bool canDestBeBlack = false;

        MoveType mt;

        PotentialMoveInfo(bool,bool,bool,MoveType);
};

#endif
