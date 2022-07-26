#include <vector>
#include <iostream>
#include "Piece.h"
#include "TextualDisplay.h"
#include "Board.h"

using namespace std;

TextualDisplay::TextualDisplay(int rows, int cols) : Display{rows, cols}, displayGrid{vector<vector<char>>()} {
    for (auto i = 0; i < rows; ++i) {
        displayGrid.emplace_back();
        for (auto j = 0; j < cols; ++j) {
            displayGrid[i].push_back((i + j) % 2 == 0 ? ' ' : '_');
        }
    }
}

void TextualDisplay::setSquare(int r, int c, PieceType p, bool isWhite) {
    if (p == PieceType::EMPTY) {
        displayGrid[r][c] = (r + c) % 2 == 0 ? ' ' : '_';
    } else {
        char piece = Piece::letters[p];
        displayGrid[r][c] = isWhite ? static_cast<char>(toupper(piece)) : piece;
    }
}
    
void TextualDisplay::display(State s) {
    for (int i = 0; i < rows; ++i) {
        cout << rows - i << ' ';
        for (int j = 0; j < cols; ++j) {
            cout << displayGrid[i][j];
        }   
        cout << endl;
    }
    cout << endl << "  abcdefgh" << endl;
    
    if (s == State::WHITE_CHECK) cout << endl << "White is in check." << endl;
    else if (s == State::BLACK_CHECK) cout << endl << "Black is in check." << endl;
    else if (s == State::WHITE_WIN) cout << endl << "Checkmate! White wins!" << endl;
    else if (s == State::BLACK_WIN) cout << endl << "Checkmate! Black wins!" << endl;
    else if (s == State::STALEMATE) cout << endl << "Stalemate!" << endl;
    else if (s == State::WHITE_RESIGN) cout << endl << "Black wins!" << endl;
    else if (s == State::BLACK_RESIGN) cout << endl << "White wins!" << endl;
}
