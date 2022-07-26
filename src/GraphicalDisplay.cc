#include <vector>
#include <iostream>

#include "Piece.h"
#include "GraphicalDisplay.h"
#include "Board.h"
#include "colours.h"

using namespace std;

GraphicalDisplay::GraphicalDisplay(int rows, int cols) 
        : Display{rows, cols}, w{400}, h{400}, mh{100}, dw{w/cols}, dh{h/rows}, screen{Screen{w,h+mh}} {
    for (auto y = 0; y < rows; ++y) {
        for (auto x = 0; x < cols; ++x) {
            screen.draw_rect(x * dw, y * dh, dw, dh, (x+y) % 2 == 0 ? WHITE : BLACK);
        }
    }

    screen.add_img("P", "imgs/Chess_plt60.png");
    screen.add_img("p", "imgs/Chess_pdt60.png");
    screen.add_img("B", "imgs/Chess_blt60.png");
    screen.add_img("b", "imgs/Chess_bdt60.png");
    screen.add_img("N", "imgs/Chess_plt60.png");
    screen.add_img("n", "imgs/Chess_plt60.png");
    screen.add_img("R", "imgs/Chess_rlt60.png");
    screen.add_img("r", "imgs/Chess_rdt60.png");
    screen.add_img("Q", "imgs/Chess_qlt60.png");
    screen.add_img("q", "imgs/Chess_qdt60.png");
    screen.add_img("K", "imgs/Chess_klt60.png");
    screen.add_img("k", "imgs/Chess_kdt60.png");
}

void GraphicalDisplay::setSquare(int r, int c, PieceType p, bool isWhite) {
    if (p == PieceType::EMPTY) {
        screen.draw_rect(c * dw, r * dh, dw, dh, (r+c) % 2 == 0 ? WHITE : BLACK);
    } else {
        char piece = Piece::letters[p];
        if (isWhite) piece = static_cast<char>(toupper(piece));
        screen.draw_img(string{piece}, c * dw, r * dh);
    }
}
    
void GraphicalDisplay::display(State s) {
    screen.update();
}
