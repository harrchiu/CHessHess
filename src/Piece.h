#include <utility> 

enum PieceType { Pawn=0, Rook=1, Knight=2, Bishop=3, Queen=4, King=5 };

class Piece {
    public:
        virtual std::vector<std::vector<std::pair<int,int>>> 
            getMoveDirections() = 0;
        bool isWhite = false;
        PieceType type;
        Piece();
        ~Piece();
};
