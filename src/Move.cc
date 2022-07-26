#include "Move.h"
#include "Piece.h"

#include <utility>

using namespace std;

// Move::Move(int sr, int sc,int er, int ec, PieceType piece=PieceType::EMPTY, 
//     PieceType captured=PieceType::EMPTY,PieceType promotedTo=PieceType::EMPTY) :
//     start{make_pair(sr,sc)}, end{make_pair(er,ec)}, piece{piece}, 
//     capturedPiece{captured}, promotedTo{promotedTo}
// {}
Move::Move(int sr, int sc,int er, int ec, bool isSideWhite, MoveType mt, PieceType piece, 
    PieceType captured,PieceType promotedTo) :
    start{make_pair(sr,sc)}, end{make_pair(er,ec)}, isSideWhite{isSideWhite}, 
    piece{piece}, capturedPiece{captured}, promotedTo{promotedTo}, moveType{mt} {};

std::ostream &operator<<(std::ostream &, const Move &m) {
    int gridSize = 8;
    string cols = "abcdefgh";
    string pieces = "PRNBQK";

    char printPiece = pieces[m.piece];
    if (printPiece == 'P') printPiece = '\0';
    cout << printPiece << cols[m.end.second] << gridSize - m.end.first;
    // cout << m.start.second << m.start.first << m.end.second << m.end.first;


    if (m.moveType == MoveType::PROMOTION){
        char promotedToPiece = pieces[m.promotedTo];
        cout << promotedToPiece;
    }
    return cout;
};
