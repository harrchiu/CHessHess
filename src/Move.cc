#include "Move.h"
#include "Piece.h"

#include <utility>

using namespace std;

// CTOR
Move::Move(int sr, int sc,int er, int ec, bool isSideWhite, MoveType mt, PieceType piece, 
    PieceType captured,PieceType promotedTo) :
    start{make_pair(sr,sc)}, end{make_pair(er,ec)}, 
    piece{piece}, capturedPiece{captured}, isSideWhite{isSideWhite}, promotedTo{promotedTo}, moveType{mt} {};

// unambiguously gives move notation in conjunction w otherMoves (if given)
string Move::getAlgNotation(const vector<Move>& otherMoves) const {
    string ret = "";
    int gridSize = 8;
    string cols = "abcdefgh";

    // special quirky notation for castling ugh
    if (moveType == MoveType::CASTLE_K_SIDE){
        return "O-O";
    }
    else if (moveType == MoveType::CASTLE_Q_SIDE){
        return "O-O-O";
    }

    // get the piece (we don't print P for pawn)
    char printPiece = toupper(Piece::letters[piece]);
    if (printPiece != 'P') 
        ret += printPiece;

    // see if move is ambiguous
    // --> another move has the same piecetype + dest, and same r or c
    bool needRow = false, needCol = false;
    if (!otherMoves.empty()){
        for (const Move &om:otherMoves){
            // cannot be the same piece
            if (om.piece == piece && om.start.first == start.first
                 && om.start.second == start.second) continue;

            // ensure end coordinates actually match
            if (om.piece != piece || om.end.first != end.first
                || om.end.second != end.second) continue;

            needRow |= start.first == om.start.first;
            needCol |= start.second == om.start.second;
        }

        // add additional coordinate info where necessary
        // need the row if the col's match and vice versa
        if (needRow) ret += cols[start.second];
        if (needCol) ret += '0' + (gridSize-start.first);
    }

    // if it was a capture or enpassant, include the x
    // also need to reinstate the pawn column 
    if (capturedPiece != PieceType::EMPTY || moveType == EN_PASSANT){
        if (printPiece == 'P' && !needRow) ret += cols[start.second];
        ret += 'x';
    }

    // the actual destination square
    ret += cols[end.second];
    ret += '0' + (gridSize - end.first);

    // add the promotedTo piecetype for promotion 
    if (moveType == MoveType::PROMOTION){
        char promotedToPiece = toupper(Piece::letters[promotedTo]);
        ret += '=';
        ret += promotedToPiece;
    }
    return ret;
};

std::ostream &operator<<(std::ostream &, const Move &m) {
    return cout << m.getAlgNotation();
}
