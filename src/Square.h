class Square {
    public:
        int row, col;
        Piece* piece;
        Square(int, int, Piece*);
        ~Square();
};
