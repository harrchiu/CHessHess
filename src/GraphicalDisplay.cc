#include <vector>
#include <iostream>

#include "Piece.h"
#include "GraphicalDisplay.h"
#include "Board.h"
#include "colours.h"

using namespace std;

// CTOR
GraphicalDisplay::GraphicalDisplay(int rows, int cols) 
        : Display{rows, cols}, w{480}, h{480}, rankw{20}, fileh{20}, messageh{60}, dw{w/cols}, dh{h/rows}, screen{Screen{w+rankw,h+fileh+messageh}} {
    // add images of pieces that could be drawn
    screen.add_img("P", "graphics/Chess_plt60.png");
    screen.add_img("p", "graphics/Chess_pdt60.png");
    screen.add_img("B", "graphics/Chess_blt60.png");
    screen.add_img("b", "graphics/Chess_bdt60.png");
    screen.add_img("N", "graphics/Chess_nlt60.png");
    screen.add_img("n", "graphics/Chess_ndt60.png");
    screen.add_img("R", "graphics/Chess_rlt60.png");
    screen.add_img("r", "graphics/Chess_rdt60.png");
    screen.add_img("Q", "graphics/Chess_qlt60.png");
    screen.add_img("q", "graphics/Chess_qdt60.png");
    screen.add_img("K", "graphics/Chess_klt60.png");
    screen.add_img("k", "graphics/Chess_kdt60.png");
}

// display - draws board to SDL screen
void GraphicalDisplay::display(State s) {
    // draw board
    screen.draw_rect(0, 0, w + rankw, h + fileh + messageh, White);
    for (auto y = 0; y < rows; ++y) {
        for (auto x = 0; x < cols; ++x) {
            char square = displayGrid[y][x];
            if (square == '_') {
                screen.draw_rect(x * dw + rankw, y * dh, dw, dh, Gray);
            } else {
                screen.draw_rect(x * dw + rankw, y * dh, dw, dh, (x + y) % 2 == 0 ? White : Gray);
                screen.draw_img(string{square}, x * dw + rankw, y * dh);
            }
        }
    }

    // draw coordinates
    string rank = "87654321";
    string file = "abcdefgh";
    for (auto y = 0; y < rows; ++y) {
        screen.draw_string(string{rank[y]}, 0, y * dh, Black);
    }
    for (auto x = 0; x < cols; ++x) {
        screen.draw_string(string{file[x]}, x * dw + rankw, h, Black);
    }

    // draw message
    string toDraw;
    if (s == State::WHITE_CHECK) toDraw = "White is in check.";
    else if (s == State::BLACK_CHECK) toDraw = "Black is in check.";
    else if (s == State::WHITE_WIN) toDraw = "Checkmate! White wins!";
    else if (s == State::BLACK_WIN) toDraw = "Checkmate! Black wins!";
    else if (s == State::STALEMATE) toDraw = "Stalemate!";
    else if (s == State::WHITE_RESIGN) toDraw = "Black wins!";
    else if (s == State::BLACK_RESIGN) toDraw = "White wins!";

    if (s != State::REGULAR) screen.draw_string(toDraw, 0, h + fileh + messageh/2, Black);

    screen.update();
}
