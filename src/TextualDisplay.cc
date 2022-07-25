#include <vector>
#include <iostream>
#include "Piece.h"

using namespace std;

void TextualDisplay::update() {}
    
void TextualDisplay::display() {
    char[6] letters = {'p','r','n','b','q','k'};

    vector<vector<Square>> myBoard = board->getBoard(); 
    for (int i=0;i<myBoard.getRows();++i) {
        cout << myBoard.getRows() - i << ' ';
        for (int j=0;j<myBoard.getCols();++j) {
            if (!myBoard[i][j].piece) {
                cout << ((i+j)%2 == 0) ? ' ' : '_';
            } else {
                cout << (square.piece->isWhite 
                            ? letters[square.piece->type].toUpper() 
                            : letters[square.piece->type]);
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "  abcdefgh" << endl;
}
