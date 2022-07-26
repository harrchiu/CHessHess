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
    float whiteWins=0, blackWins=0;
    bool didSetup = false;
    string s;
    Outcome outcome;

    // TODO: how to end a game
    while (cin >> s) {		// match
        Board b(8,8);		// initialize a default board
        Game g(&b);  

        // TODO: have some output to say
        // cout << "Welcome to chess!" << endl;
        // cout << "White: " << score
        // cout << "Black: " << score
        // cout << endl
        // cout << "Enter "setup" to set up a custom board, or "game" to start a game"
        
        while (s != "game") {
            if (s == "setup") {
                g.setup();
                didSetup = true;

            //    b.printLegalMoves();
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
                g.setPlayer(PieceColour::WHITE, new Human(PieceColour::WHITE));
            } else if (whitePlayer[0] == 'a' || whitePlayer[0] == 'A') {
                if (whitePlayer.find('1') != string::npos) {
                    g.setPlayer(PieceColour::WHITE, new Ai1(PieceColour::WHITE));
                } else if (whitePlayer.find('2') != string::npos) {
                    g.setPlayer(PieceColour::WHITE, new Ai2(PieceColour::WHITE));
                } else if (whitePlayer.find('3') != string::npos) {
                    g.setPlayer(PieceColour::WHITE, new Ai3(PieceColour::WHITE));
                } else if (whitePlayer.find('4') != string::npos) {
                    g.setPlayer(PieceColour::WHITE, new Ai4(PieceColour::WHITE));
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
                g.setPlayer(PieceColour::BLACK, new Human(PieceColour::BLACK));
            } else if (blackPlayer[0] == 'a' || blackPlayer[0] == 'A') {
                if (blackPlayer.find('1') != string::npos) {
                    g.setPlayer(PieceColour::BLACK, new Ai1(PieceColour::BLACK));
                } else if (blackPlayer.find('2') != string::npos) {
                    g.setPlayer(PieceColour::BLACK, new Ai2(PieceColour::BLACK));
                } else if (blackPlayer.find('3') != string::npos) {
                    g.setPlayer(PieceColour::BLACK, new Ai3(PieceColour::BLACK));
                } else if (blackPlayer.find('4') != string::npos) {
                    g.setPlayer(PieceColour::BLACK, new Ai4(PieceColour::BLACK));
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
        
        g.display();
        outcome = g.playGame();


        // handle result here
        switch (outcome) {
            case Outcome::BLACK_VICTORY:
                ++blackWins;
            case Outcome::WHITE_VICTORY:
                ++whiteWins;
            case Outcome::TIE:
                whiteWins += 0.5;
                blackWins += 0.5;
            default:
                break;
        }
    }

    cout << "Final Score:" << endl;
    cout << "White: " << ((whiteWins == (int)(whiteWins)) ? (int) whiteWins : whiteWins) << endl;
    cout << "Black: " << ((blackWins == (int)(blackWins)) ? (int) blackWins : blackWins) << endl;
    return 0;
}
