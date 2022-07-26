#include "Move.h"
#include "Piece.h"

#include <utility>

using namespace std;

// CTOR
Move::Move(int sr, int sc,int er, int ec, bool isSideWhite, MoveType mt, PieceType piece, 
    PieceType captured,PieceType promotedTo) :
    start{make_pair(sr,sc)}, end{make_pair(er,ec)}, 
    piece{piece}, capturedPiece{captured}, isSideWhite{isSideWhite}, promotedTo{promotedTo}, moveType{mt} {};

// operator overload for printing moves
std::ostream &operator<<(std::ostream &, const Move &m) {
    int gridSize = 8;
    string cols = "abcdefgh";
    string pieces = "PRNBQK";

    if (m.moveType == MoveType::CASTLE_K_SIDE){
        return cout << "O-O";
    }
    else if (m.moveType == MoveType::CASTLE_Q_SIDE){
        return cout << "O-O-O";
    }

    char printPiece = pieces[m.piece];
    if (printPiece == 'P') printPiece = '\0';
    cout << printPiece;
    if (m.capturedPiece != PieceType::EMPTY || m.moveType == EN_PASSANT){
        if (printPiece == '\0') cout << cols[m.start.second];
        cout << 'x';
    }
    cout << cols[m.end.second] << gridSize - m.end.first;
    // cout << m.start.second << m.start.first << m.end.second << m.end.first;


    if (m.moveType == MoveType::PROMOTION){
        char promotedToPiece = pieces[m.promotedTo];
        cout << '=' << promotedToPiece;
    }
    return cout;
};
