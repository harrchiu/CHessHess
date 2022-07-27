#include "Square.h"
#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "Bishop.h"
#include <memory>

using namespace std;

// CTOR
Square::Square(int& row, int& col, Piece* p) 
    : row{row}, col{col}, piece{move(p)} {}

// DTOR
Square::~Square() {}

// CCTOR
Square::Square(const Square& o) : row{o.row}, col{o.col} {
    Piece* o_piece = o.piece.get();
    if (o_piece == nullptr){
        return;
    }
    
    bool isWhite = o_piece->getIsWhite();

    switch (o_piece->type()) {
        case PieceType::PAWN:
            piece = make_unique<Pawn>(isWhite);
            break;
        case PieceType::ROOK:
            piece = make_unique<Rook>(isWhite);
            break;
        case PieceType::KNIGHT:
            piece = make_unique<Knight>(isWhite);
            break;
        case PieceType::BISHOP:
            piece = make_unique<Bishop>(isWhite);
            break;
        case PieceType::QUEEN:
            piece = make_unique<Queen>(isWhite);
            break;
        case PieceType::KING:
            piece = make_unique<King>(isWhite);
            break;
        default:
            break;
    }
}

