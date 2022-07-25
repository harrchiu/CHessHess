#include <iostream>
#include <string>

#include "Game.h"
#include "Board.h"

using namespace std;

int main() {
    int home=0, away=0;
    string s;

    while (cin >> s) {		// match
        Board b(8,8);		// initialize a default board
        
        while (s != "game ___"){
            cin >> s;
            if (s == "setup")
                b.setup();
        }
        Game g(b);	
        result = g.playGame();	

        // handle result here
    }

    return 0;
}
