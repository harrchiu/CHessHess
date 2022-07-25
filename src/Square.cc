#include "Square.h"
#include "Piece.h"

Square::Square(int row, int col, Piece* p) : row{row}, col{col}, piece{make_unique<Piece>(p)} {};
Square::~Square() {};
