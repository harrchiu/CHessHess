#include <utility>
#include 'piece.h'

struct Move {
    std::pair<int,int> start;
    std::pair<int,int> end;
    PieceType piece;
    PieceType capturedPiece;
}