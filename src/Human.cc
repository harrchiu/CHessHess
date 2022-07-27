#include "Human.h"
#include "Move.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

// CTOR
Human::Human(PieceColour p) : Player{p} {}

Move Human::getMove(Board* b, bool isWhiteToMove){
    string cols = "ABCDEFGH";
    string rows = "87654321";
    string startSquare;
    string endSquare;
    size_t c,r,x2,y2;
    bool validSquare = false;
    
    // get a valid start square
    while (!validSquare) {
        cin >> startSquare;
        // descriptive notation ("e2 ...")
        if (startSquare.length() == 2) {
            r = cols.find(toupper(startSquare[0]));
            c = rows.find(startSquare[1]);
            if (c == string::npos || r == string::npos) {
                cout << "Invalid Start Square" << endl;   
            } else {
                validSquare = true;
            }
        }
    }
    // get a valid end square
    validSquare = false;
    while (!validSquare) {
        cin >> endSquare;
        if (endSquare.length() == 2) {
            y2 = cols.find(toupper(endSquare[0]));
            x2 = rows.find(endSquare[1]);
            if (x2 == string::npos || y2 == string::npos) {
                cout << "Invalid End Square" << endl;   
            } else {
                validSquare = true;
            }
        }
    }
    Move m((int)c,(int)r,(int)x2,(int)y2);
    return m;
}

