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
#include "TextualDisplay.h"

using namespace std;

int main() {
    int home=0, away=0;
    bool didSetup = false;
    string s;
    string result;

    while (cin >> s) {		// match
        Board b(8,8);		// initialize a default board
        Game g(&b);  
        
        while (s != "game") {
            if (s == "setup") {
                g.setup();
                td.display();
                didSetup = true;

               b.printLegalMoves();
            }
            g.display();
            cin >> s;
        }

        string whitePlayer;
        string blackPlayer;
        bool keepGoing = true;
        if (!didSetup) {
            b.setupInitialPosition();   // TODO: replace with g.setupInitialGameState() or sth
        }

        //set white player
        cout << "Set White Player: ";
        while (keepGoing) {
            cin >> whitePlayer;
            keepGoing = false;
            if (whitePlayer[0] == 'h' || whitePlayer[0] == 'h') {
                g.setPlayer(PieceColour::WHITE, new Human());
            } else if (whitePlayer[0] == 'a' || whitePlayer[0] == 'A') {
                if (whitePlayer.find('1') != string::npos) {
                    g.setPlayer(PieceColour::WHITE, new Ai1());
                } else if (whitePlayer.find('2') != string::npos) {
                    g.setPlayer(PieceColour::WHITE, new Ai2());
                } else if (whitePlayer.find('3') != string::npos) {
                    g.setPlayer(PieceColour::WHITE, new Ai3());
                } else if (whitePlayer.find('4') != string::npos) {
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
        while (keepGoing) {
            cin >> blackPlayer;
            keepGoing = false;
            if (blackPlayer[0] == 'h' || blackPlayer[0] == 'h') {
                g.setPlayer(PieceColour::BLACK, new Human());
            } else if (blackPlayer[0] == 'a' || blackPlayer[0] == 'A') {
                if (blackPlayer.find('1') != string::npos) {
                    g.setPlayer(PieceColour::BLACK, new Ai1());
                } else if (blackPlayer.find('2') != string::npos) {
                    g.setPlayer(PieceColour::BLACK, new Ai2());
                } else if (blackPlayer.find('3') != string::npos) {
                    g.setPlayer(PieceColour::BLACK, new Ai3());
                } else if (blackPlayer.find('4') != string::npos) {
                    g.setPlayer(PieceColour::BLACK, new Ai4());
                }
                else {
                    cout << "here";
                    keepGoing = true;
                    cout << "Invalid Black Player" << endl;
                }
            } else {
                keepGoing = true;
                cout << "Invalid Black Player" << endl;
            }
        }
        
        g.display();
        result = g.playGame();

        if (result == "somfalsdkfalksdjf"){
            ++home;
        }
        else{
            ++away;
        }

        // handle result here
    }
    return 0;
}
