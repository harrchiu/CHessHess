#ifndef SQUARE
#define SQUARE

class Square {
    public:
        int row, col;
        std::unique_ptr<Piece> piece;
        Square(int, int, Piece*);
        ~Square();
};

#endif