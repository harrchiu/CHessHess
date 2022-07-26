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
    start{make_pair(sr,sc)}, end{make_pair(er,ec)}, 
    piece{piece}, capturedPiece{captured}, promotedTo{promotedTo} {};

std::ostream &operator<<(std::ostream &, const Move &m) {
    int gridSize = 8;
    string cols = "ABCDEFGH";
    cout << cols[m.start.second] << gridSize - m.start.first
        << cols[m.end.second] << gridSize - m.end.first;
    // cout << m.start.second << m.start.first << m.end.second << m.end.first;


    string pieces = "PRNBQK";
    if (m.moveType == MoveType::PROMOTION){
        char promotedToPiece = pieces[m.promotedTo];
        cout << promotedToPiece;
    }
    return cout;
};
