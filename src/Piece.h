#ifndef PIECE
#define PIECE

#include <utility> 

enum PieceColour { White=0, Black=1 };
enum PieceType { Pawn=0, Rook=1, Knight=2, Bishop=3, Queen=4, King=5 };

class Piece {
    public:
        virtual std::pair<int,int> getMoveDirections();
        virtual PieceType type();
};

#endif