#include <vector>
#include <iostream>

#include "Piece.h"
#include "GraphicalDisplay.h"
#include "Board.h"

using namespace std;

GraphicalDisplay::GraphicalDisplay(int rows, int cols) : Display{rows, cols} {}

void GraphicalDisplay::setSquare(int row, int col, PieceType p, bool isWhite) {
    // TODO: ryan: implement setSquare
}

void GraphicalDisplay::update(const Move &m) {
    // TODO: ryan: implement update
}

void GraphicalDisplay::restore(const Move &m) {
    // TODO: ryan: implement restore
}
    
void GraphicalDisplay::display(State s) {
    // TODO: ryan: implement display
}
