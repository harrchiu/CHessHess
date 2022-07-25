#include <iostream>
#include <vector>
#include <string>

#include "Board.h"
#include "Piece.h"
#include "Square.h"
#include "Move.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"

using namespace std;

// initialize board to empty position
Board::Board(int rows, int cols) : rows{rows}, cols{cols} {
    for (int i=0;i<rows;++i){
        vector<Square> cRow;
        for (int j=0;j<cols;++j){
            cRow.emplace_back(i,j,nullptr);
        }
        grid.push_back(cRow);
    }
}

// l-value/deep copy ctor
// Board::Board(const Board& o) : rows{o.rows}, cols{o.cols} {
//     for (int i=0;i<rows;++i){
//         vector<Square> cRow;
//         for (int j=0;j<cols;++j){
//             Piece* copyPiece = nullptr;
//             if (grid[i][j].piece){
//                 copyPiece = new Piece(grid[i][j].piece);
//             }
//             cRow.push_back(Square(i,j,copyPiece));
//         }
//         grid.push_back(cRow);
//     }
// }

// assume board is empty (not deleting pieces)
void Board::setupInitialPosition() {
    // vector<vector<Piece*>> piecePtrs = {
    //     {new Rook(false),new Knight(false),new Bishop(false),new Queen(false),
    //     new King(false),new Bishop(false),new Knight(false),new Rook(false)},
    //     {new Pawn(false), new Pawn(false), new Pawn(false), new Pawn(false),
    //     new Pawn(false), new Pawn(false), new Pawn(false), new Pawn(false)},

    //     {new Rook(true),new Knight(true),new Bishop(true),new Queen(true),
    //     new King(true),new Bishop(true),new Knight(true),new Rook(true)},
    //     {new Pawn(true), new Pawn(true), new Pawn(true), new Pawn(true),
    //     new Pawn(true), new Pawn(true), new Pawn(true), new Pawn(true)}
    // };
    // vector<int> startingRows = {0,1,6,7};

    // for (int r: startingRows){
    //     for (int c=0;c<8;++c){
    //         grid[r][c].piece = make_unique(piecePtrs[r][c];
    //     }
    // }

    // pawns
    for (int c=0;c<8;++c){
        grid[1][c].piece = make_unique<Pawn>(false);
        grid[6][c].piece = make_unique<Pawn>(true);
    }

    // rest
    for (int r: {0,7}){
        grid[r][0].piece = make_unique<Rook>(r == 7);
        grid[r][1].piece = make_unique<Knight>(r == 7);
        grid[r][2].piece = make_unique<Bishop>(r == 7);
        grid[r][3].piece = make_unique<Queen>(r == 7);
        grid[r][4].piece = make_unique<King>(r == 7);
        grid[r][5].piece = make_unique<Bishop>(r == 7);
        grid[r][6].piece = make_unique<Knight>(r == 7);
        grid[r][7].piece = make_unique<Rook>(r == 7);
    }
}

Board::~Board() {
    // changed to unique ptr so not necessary?

    // for (int i=0;i<rows;++i){
    //     for (int j=0;j<cols;++j){
    //         if (grid[i][j].piece){
    //             delete grid[i][j].piece;
    //         }
    //     }
    // }
}

int Board::getRows() { return rows; };
int Board::getCols() { return cols; };
bool Board::isOnBoard(const int r, const int c){
    return r >= 0 && c >= 0 && r < rows && c < cols;
}

pair<bool, bool> Board::isMate() {
    pair<bool, bool> checkStatus = isCheck();
    return {getLegalMoves(true).size() == 0 && checkStatus.first,
        getLegalMoves(false).size() == 0 && checkStatus.second
    };
};


vector<Move> Board::getMoves(bool isSideWhite) {
    vector<Move> moves;

    for (int r=0;r<rows;++r){
        for (int c=0;c<cols;++c){

            // must be a non-empty piece of the same color
            Piece* curPiece = grid[r][c].piece.get();
            if (nullptr == curPiece) continue;
            if (curPiece->getIsWhite() != isSideWhite) continue;

            // e.g. dirs is all the moves going right
            for (vector<PotentialMove> dirs : curPiece->getMoveDirections()){
                for (PotentialMove pm : dirs){
                    int newR = r + pm.rowMov;
                    int newC = c + pm.colMov;
                    if (!isOnBoard(newR, newC)) break;
                    

                    // pawn is fucked
                    // if (curPiece->type == Pawn){
                    //     // capture?
                    //     // enpassant?
                    //     // first move?
                    // }
                    // else if (curPiece->type == King){
                    //     // castling
                    // }

                    // if (grid)
                    
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
    // for (Move m : moves) {
    //     Board boardCopy = Board(*this); 
    //     vector<Move> counterMoves = getMoves(isSideWhite);
    // }


    return legalMoves;
}

void Board::makeMove(Move m, bool isWhiteToMove) {
    vector<Move> validMoves = getLegalMoves(isWhiteToMove);
    for(int i=0;i<(int) validMoves.size();i++) {
        if (validMoves[i].start == m.start && validMoves[i].end == m.end) {
            applyMove(validMoves[i]);
        }
    }
}

void Board::applyMove(Move m) {

}


vector<vector<Square>>& Board::getBoard() {
    return grid;
}

pair<bool,bool> Board::isCheck() {
    return {false,false};
}
