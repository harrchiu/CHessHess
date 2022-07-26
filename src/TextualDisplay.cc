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

void TextualDisplay::setSquare(int y, int x, PieceType p, bool isWhite) {
    if (p == PieceType::EMPTY) {
        displayGrid[y][x] = (y + x) % 2 == 0 ? ' ' : '_';
    } else {
        char piece = Piece::letters[p];
        displayGrid[y][x] = isWhite ? static_cast<char>(toupper(piece)) : piece;
    }
}

void TextualDisplay::update(const Move &m) {
    // TODO: ryan: implement update
}
    
void TextualDisplay::display() {
    for (int i = 0; i < rows; ++i) {
        cout << rows - i << ' ';
        for (int j = 0; j < cols; ++j) {
            cout << displayGrid[i][j];
        }   
        cout << endl;
    }
    cout << endl << "  abcdefgh" << endl;
}
