#include <vector>
#include <iostream>
#include "Piece.h"
#include "TextualDisplay.h"
#include "Board.h"

using namespace std;

// CTOR
TextualDisplay::TextualDisplay(int rows, int cols) : Display{rows, cols} {}
    
// display - displays the grid and state
void TextualDisplay::display(State s) {
    // basic character output of board
    for (int i = 0; i < rows; ++i) {
        cout << rows - i << ' ';
        for (int j = 0; j < cols; ++j) {
            cout << displayGrid[i][j];
        }   
        cout << endl;
    }
    cout << endl << "  abcdefgh" << endl;
    
    // special messages
    if (s == State::WHITE_CHECK) cout << endl << "White is in check." << endl;
    else if (s == State::BLACK_CHECK) cout << endl << "Black is in check." << endl;
    else if (s == State::WHITE_WIN) cout << endl << "Checkmate! White wins!" << endl;
    else if (s == State::BLACK_WIN) cout << endl << "Checkmate! Black wins!" << endl;
    else if (s == State::STALEMATE) cout << endl << "Stalemate!" << endl;
    else if (s == State::WHITE_RESIGN) cout << endl << "Black wins!" << endl;
    else if (s == State::BLACK_RESIGN) cout << endl << "White wins!" << endl;
}
