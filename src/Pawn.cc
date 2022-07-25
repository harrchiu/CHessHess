#include <vector>
#include "Piece.h"
#include "Pawn.h"

using namespace std;

vector<vector<pair<int,int>>> Pawn::getMoveDirections() {
    // "white moves up the board" = smaller row
    int verticalDir = isWhite ? -1 : 1;

    vector<vector<pair<int,int>>> dirs;
    if ()
 
    return dirs;
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

PieceType Pawm::type() {
    return PieceType::Pawn;
};