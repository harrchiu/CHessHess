#ifndef PIECE_H
#define PIECE_H

#include <utility> 
#include "PotentialMove.h" 

enum PieceColour { WHITE=0, BLACK=1 };
enum PieceType { PAWN=0, ROOK=1, KNIGHT=2, BISHOP=3, QUEEN=4, KING=5 };
 
class Piece {
    bool isWhite = false;
    public:
        virtual PieceType type() = 0;
        bool getIsWhite();

        /* idea behind getMoveDirections()
            • returns vector of vectors of pairs
            • each inner vector represents a direction (i.e. right, up-left)
            • iterate through each inner vector, but skip to the next inner
                vector if we reach an invalid move, since the rest of that
                direction must be invalid

            • wonky pieces use one inner vector per move (king, knight, pawn)
        */
        virtual std::vector<std::vector<PotentialMove>> 
            getMoveDirections() = 0;
            
        Piece(bool);
        virtual ~Piece();
};

#endif
