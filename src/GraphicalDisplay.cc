#include <vector>
#include <iostream>

#include "Piece.h"
#include "GraphicalDisplay.h"
#include "Board.h"
#include "colours.h"

using namespace std;

GraphicalDisplay::GraphicalDisplay(int rows, int cols) 
        : Display{rows, cols}, w{480}, h{480}, mh{60}, dw{w/cols}, dh{h/rows}, screen{Screen{w,h+mh}} {
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
    
void GraphicalDisplay::display(State s) {
    // draw board
    for (auto y = 0; y < rows; ++y) {
        for (auto x = 0; x < cols; ++x) {
            char square = displayGrid[y][x];
            if (square == ' ') {
                screen.draw_rect(x * dw, y * dh, dw, dh, White);    
            } else if (square == '_') {
                screen.draw_rect(x * dw, y * dh, dw, dh, Black);
            } else {
                screen.draw_rect(x * dw, y * dh, dw, dh, (x + y) % 2 == 0 ? White : Black);
                screen.draw_img(string{square}, x * dw, y * dh);
            }
        }
    }
    // draw message
    screen.draw_rect(0, h, w, mh, White);
    screen.draw_string("Hi!", 0, h + mh/2, Black);

    screen.update();
}
