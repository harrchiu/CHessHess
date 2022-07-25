#include <iostream>
#include <vector>
#include <string>

#include "Board.h"
#include "Piece.h"
#include "Square.h"
#include "Move.h"

using namespace std;

// initialize board to empty position
Board::Board(int rows, int cols) : rows{rows}, cols{cols} {
    for (int i=0;i<rows;++i){
        vector<Square> cRow;
        for (int j=0;j<cols;++j){
            cRow.push_back(Square(i,j,nullptr));
        }
        grid.push_back(cRow);
    }
}

// l-value/deep copy ctor
Board::Board(const Board& o) : rows{o.rows}, cols{o.cols} {
    for (int i=0;i<rows;++i){
        vector<Square> cRow;
        for (int j=0;j<cols;++j){
            Piece* copyPiece = nullptr;
            if (grid[i][j].piece){
                copyPiece = new Piece(grid[i][j].piece);
            }
            cRow.push_back(Square(i,j,copyPiece));
        }
        grid.push_back(cRow);
    }
}


Board::~Board() {
    for (int i=0;i<rows;++i){
        for (int j=0;j<cols;++j){
            if (grid[i][j].piece){
                delete grid[i][j].piece;
            }
        }
    }
}

int Board::getRows() { return rows; };
int Board::getCols() { return cols; };
bool Board::isOnBoard(const int r, const int c){
    return r >= 0 && c >= 0 && r < rows && c < cols;
}

pair<bool, bool> Board::isMate() {
    pair<bool, bool> checkStatus = isCheck();
    return {getValidMoves(true).size() == 0 && checkStatus.first,
        getValidMoves(false).size() == 0 && checkStatus.second
    };
};


vector<Move> Board::getMoves(bool isSideWhite) {
    vector<Move> moves;

    for (int r=0;r<rows;++r){
        for (int c=0;c<cols;++c){
            // must be a non-empty piece of the same color
            Piece* curPiece = grid[r][c].piece;
            if (nullptr == curPiece) continue;
            if (curPiece->isWhite != isSideWhite) continue;

            // e.g. dirs is all the moves going right
            for (vector<pair<int,int>> dirs : curPiece->getMoveDirections()){
                for (pair<int,int> shift : dirs){
                    int newR = r + shift.first;
                    int newC = c + shift.second;
                    if (!isOnBoard(newR, newC)) break;
                    
                    // pawn is fucked
                    if (curPiece->type == Pawn){
                        // capture?
                        // enpassant?
                        // first move?
                    }
                    else if (curPiece->type == King){
                        // castling
                    }

                    if (grid)
                    
                }
            }

        }
    }

    // now, go through all moves and see if king is in check for any of them

    return moves;
}

// here we go
vector<Move> Board::getLegalMoves(bool isSideWhite) {
    vector<Move> moves = getMoves(isSideWhite);
    vector<Move> legalMoves = {};
    for (Move m : moves) {
        Board boardCopy = Board(*this); 
        vector<Move> counterMoves = getMoves(isSideWhite);
    }


    return legalMoves;
}

void Board::setup() {
    string cmd;
    bool keepGoing = true;
    string validPieces = "prnbqkPRNBQK";

    while (keepGoing) {
        cin >> cmd;

        //start with this tmr albert! 
        // ok albert :) love u ! good luck with your work sweetie pie <3
        // 80 character rule please
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
                    if (square.piece && square.piece->type == PieceType::King){ 
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
