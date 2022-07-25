#include <iostream>
#include <string>

#include "Game.h"
#include "Board.h"
#include "Human.h"
#include "Ai1.h"
#include "Ai2.h"
#include "Ai3.h"
#include "Ai4.h"
#include "Piece.h"

using namespace std;

int main() {
    int home=0, away=0;
    home++; away++;
    string s;
    string result;

    while (cin >> s) {		// match
        Board b(8,8);		// initialize a default board
        Game g(&b);
        
        while (s != "game"){
            cin >> s;
            if (s == "setup")
                g.setup();
        }
        string whitePlayer;
        string blackPlayer;
        bool keepGoing = true;

        //set white player
        cout << "Set White Player: ";
        cin >> whitePlayer;
        while (keepGoing) {
            keepGoing = false;
            if (whitePlayer[0] == 'h' || whitePlayer[0] == 'h') {
                g.setPlayer(PieceColour::WHITE, new Human());
            } else if (whitePlayer[0] == 'a' || whitePlayer[0] == 'A') {
                if (whitePlayer.find(1) != string::npos) {
                    g.setPlayer(PieceColour::WHITE, new Ai1());
                } else if (whitePlayer.find(2) != string::npos) {
                    g.setPlayer(PieceColour::WHITE, new Ai2());
                } else if (whitePlayer.find(3) != string::npos) {
                    g.setPlayer(PieceColour::WHITE, new Ai3());
                } else if (whitePlayer.find(4) != string::npos) {
                    g.setPlayer(PieceColour::WHITE, new Ai4());
                }
                else {
                    keepGoing = true;
                    cout << "Invalid White Player" << endl;
                }
            } else {
                keepGoing = true;
                cout << "Invalid White Player" << endl;
            }
        }
        cout << "White Player set" << endl;

        //set black player
        keepGoing = true;
        cout << "Set Black Player: ";
        cin >> blackPlayer;
        while (keepGoing) {
            keepGoing = false;
            if (blackPlayer[0] == 'h' || blackPlayer[0] == 'h') {
                g.setPlayer(PieceColour::BLACK, new Human());
            } else if (blackPlayer[0] == 'a' || blackPlayer[0] == 'A') {
                if (blackPlayer.find(1) != string::npos) {
                    g.setPlayer(PieceColour::BLACK, new Ai1());
                } else if (blackPlayer.find(2) != string::npos) {
                    g.setPlayer(PieceColour::BLACK, new Ai2());
                } else if (blackPlayer.find(3) != string::npos) {
                    g.setPlayer(PieceColour::BLACK, new Ai3());
                } else if (blackPlayer.find(4) != string::npos) {
                    g.setPlayer(PieceColour::BLACK, new Ai4());
                }
                else {
                    keepGoing = true;
                    cout << "Invalid Black Player" << endl;
                }
            } else {
                keepGoing = true;
                cout << "Invalid Black Player" << endl;
            }
        }

        result = g.playGame();	

        // handle result here
    }
    return 0;
}
