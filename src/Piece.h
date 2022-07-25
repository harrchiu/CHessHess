#include <utility> 

enum PieceType { Pawn=0, Rook=1, Knight=2, Bishop=3, Queen=4, King=5 };

class Piece {
    public:
        Board* board;
        
        bool isWhite = false;
        PieceType type;

        /* idea behind getMoveDirections()
            • returns vector of vectors of pairs
            • each inner vector represents a direction (i.e. right, up-left)
            • iterate through each inner vector, but skip to the next inner
                vector if we reach an invalid move, since the rest of that
                direction must be invalid

            • wonky pieces use one inner vector per move (king, knight, pawn)
        */
        virtual std::vector<std::vector<std::pair<int,int>>> 
            getMoveDirections() = 0;
            
        Piece();
        Piece(Piece&);   // deep-copy pieces
        ~Piece();
};
