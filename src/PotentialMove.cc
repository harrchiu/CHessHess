#include "PotentialMove.h"

PotentialMove::PotentialMove(int r, int c, bool canBeEmpty, bool canBeWhite,
    bool canBeBlack, MoveType mt) : 
    rowMov{r}, colMov{c}, canDestBeEmpty{canBeEmpty}, 
    canDestBeWhite{canBeWhite}, canDestBeBlack{canBeBlack}, mt{mt} {};
