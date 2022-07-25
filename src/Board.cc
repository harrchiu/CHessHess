#include <iostream>
#include <vector>
#include <string>

#include "Board.h"
#include "Piece.h"
#include "Square.h"
using namespace std;

Board::Board(int rows, int cols) : rows{rows}, cols{cols} {
    for (int i=0;i<rows;++i){
        vector<Square> cRow;
        for (int j=0;j<cols;++j){
            cRow.push_back(Square(i,j,nullptr));
        }
        grid.push_back(cRow);
    }
}

Board::~Board() {}

void Board::getRows() { return rows };
void Board::getCol() { return cols };

void Board::setup() {
    string cmd;
    bool keepGoing = true;
    string validPieces = "prnbqkPRNBQK";

    while (keepGoing) {
        cin >> cmd;

        //start with this tmr albert! ok albert :) love u ! good luck with your work sweetie pie <3
        if (cmd.compare("+") == 0) {
            char inPiece;
            string inSquare;
            cin >> inPiece;
            if (!validPieces.find(inPiece))
            cin >> inSquare;
            if (s.find('[') != std::string::npos)
        }
        if (cmd.compare("done") == 0) {
            //Check for exactly one white king and one black king
            int whiteKingCount = 0;
            int blackKingCount = 0;
            for (auto vec : grid) {
                for (auto square : vec) {
                    if (square.piece && square.piece->type == PieceType::King) { 
                        if (square.piece->isWhite) {
                            ++whiteKingCount;
                        } else {
                            ++blackKingCount;
                        }
                    }
                }
            }
            if (whiteKingCount != 1) {
                cout << "Board must contain EXACTLY one white king" << endl;
            }
            if (blackKingCount != 1) {
                cout << "Board must contain EXACTLY one black king" << endl;
            }
            //Check for pawns in first and last row
            for (auto square : grid.at(0)) {
                if (square.piece && square.piece->type == PieceType::Pawn){
                    cout << "Pawns cannot be in first row" << endl;
                }
            }
            for (auto square : grid.back()) {
                if (square.piece && square.piece->type == PieceType::Pawn){
                    cout << "Pawns cannot be in last row" << endl;
                }
            }
            //Check that no king is in check
            pair<bool,bool> checkPair = isCheck();
            if (checkPair.first) {
                cout << "White king is in check" << endl;
            } if (checkPair.second) {
                cout << "Black king is in check" << endl;
            }
            
        }
        
    }    
}
