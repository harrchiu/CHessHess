#ifndef SQUARE
#define SQUARE

#include <memory>

class Square {
    public:
        int row, col;
        std::unique_ptr<Piece> piece;
        Square(int, int, Piece*);
        ~Square();
};

#endif