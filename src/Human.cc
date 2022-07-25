#include "Human.h"
#include "Move.h"

#include <string>
#include <iostream>

using namespace std;

Move Human::getMove(Board *b) {
    string cols = "ABCDEFGH";
    string rows = "87654321";
    string startSquare;
    string endSquare;
    size_t x,y,x2,y2;
    bool validSquare = false;
    
    while (!validSquare) {
        cin >> startSquare;
        if (startSquare.length() == 2) {
            x = cols.find(toupper(startSquare[0]));
            y = rows.find(startSquare[1]);
            if (x == string::npos || y == string::npos) {
                cout << "Invalid Start Square" << endl;   
            } else {
                validSquare = true;
            }
        }
    }
    validSquare = false;
    while (!validSquare) {
        cin >> endSquare;
        if (endSquare.length() == 2) {
            x2 = cols.find(toupper(endSquare[0]));
            y2 = rows.find(endSquare[1]);
            if (x2 == string::npos || y2 == string::npos) {
                cout << "Invalid End Square" << endl;   
            } else {
                validSquare = true;
            }
        }
    }
    Move m((int)x,(int)y,(int)x2,(int)y2);
    return m;
}

