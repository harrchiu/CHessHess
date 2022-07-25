#include "Move.h"
#include "Piece.h"

#include <utility>

using namespace std;

// Move::Move(int sr, int sc,int er, int ec, PieceType piece=PieceType::EMPTY, 
//     PieceType captured=PieceType::EMPTY,PieceType promotedTo=PieceType::EMPTY) :
//     start{make_pair(sr,sc)}, end{make_pair(er,ec)}, piece{piece}, 
//     capturedPiece{captured}, promotedTo{promotedTo}
// {}
Move::Move(int sr, int sc,int er, int ec, PieceType piece, 
    PieceType captured,PieceType promotedTo) :
    start{make_pair(sr,sc)}, end{make_pair(er,ec)}, piece{piece}, 
    capturedPiece{captured}, promotedTo{promotedTo}
{}
