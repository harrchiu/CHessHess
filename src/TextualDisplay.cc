#include <vector>
#include <iostream>
#include "Piece.h"
#include "TextualDisplay.h"

using namespace std;

void TextualDisplay::update() {}
    
void TextualDisplay::display() {
    char letters[6] = {'p','r','n','b','q','k'};


    vector<vector<Square>> myBoard = board->getBoard(); 
    
    for (int i=0;i<(int)myBoard.size();++i) {
        cout << myBoard.size() - i << ' ';
        for (int j=0;j<(int)myBoard[i].size();++j) {
            Square square = myBoard[i][j];
            if (!square.piece) {
                cout << ((i+j)%2 == 0 ? ' ' : '_');
            } else {
                cout << (square.piece->getIsWhite()
                            ? toupper(letters[square.piece->type()]) 
                            : letters[square.piece->type()]);
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "  abcdefgh" << endl;
}
