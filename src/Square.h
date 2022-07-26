#ifndef SQUARE_H
#define SQUARE_H

#include "Piece.h"
#include <memory>

class Square {
        int row, col;
    public:
        // Square(int, int, std::unique_ptr<Piece>);
        Square(int&, int&, Piece*);    
        Square(const Square&);         
        ~Square();

        std::unique_ptr<Piece> piece;
};

#endif