#ifndef SQUARE_H
#define SQUARE_H

#include "Piece.h"
#include <memory>

class Square {
    public:
        int row, col;
        std::unique_ptr<Piece> piece;
        // Square(int, int, std::unique_ptr<Piece>);
        Square(int&, int&, Piece*);    // before
        Square(const Square&);         //
        ~Square();
};

#endif