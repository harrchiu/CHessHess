#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Ai3.h"
#include "Move.h"

using namespace std;

// CTOR
Ai3::Ai3(PieceColour p) : Player{p} {}

// checkBoardScore - checks the point score of a given board 
// (Higher number if AI winning)
signed int Ai3::checkBoardScore(Board* b) {
    signed int score = 0;

    // Go through the grid and add the piece difference to the score
    for(int i=0;i<(int)b->getBoard().size();i++) {
        for(int j=0;j<(int)b->getBoard().at(i).size();j++) {
            Piece* pp = b->getBoard().at(i).at(j).piece.get();
            if (pp != nullptr) {
                signed int pieceScore;
                switch (pp->type()) {
                    case PieceType::PAWN:
                        pieceScore = 2;
                        break;
                    case PieceType::ROOK:
                        pieceScore = 10;
                        break;
                    case PieceType::KNIGHT:
                        pieceScore = 6;
                        break;
                    case PieceType::BISHOP:
                        pieceScore = 6;
                        break;
                    case PieceType::QUEEN:
                        pieceScore = 20;
                        break;
                    default:
                        pieceScore = 0;
                        break;
                }
                // if enemy piece, subtract from the score else add to it
                if (pp->getIsWhite() == !color) {
                    score = score + pieceScore;
                } else {
                    score = score - pieceScore;
                }
            }
        }
    }
    // add a point if enemy is in check, subtract one if AI is in check
    if (b->isCheck(!color,false)) {
        score += 1.0;
    } if (b->isCheck(color,false)) {
        score -= 1.0;
    }
    return score;
}

// checkMostDetrimentalResponseScore - Looks at all enemy valid moves
// and returns the score of the most detrimental one
signed int Ai3::checkMostDetrimentalResponseScore(Board* b) {
    vector<Move> validMoves = b->getLegalMoves(color);
    signed int worstScore;
    signed int curScore;

    // if enemy has no valid moves, returns 9000 if checkmate
    // and 0 if stalemate
    if (validMoves.empty()){
        if (b->isCheck(color)){
            return 9000; 
        }
        else{
            return 0;
        }
    }

    // set the worst score to the score of the first enemy valid move
    b->applyMove(validMoves.at(0));
    worstScore = checkBoardScore(b);
    b->undoLastMove();

    // check every enemy valid move and find the score, 
    // keeping track of and returning the worst one
    for(int i=0;i<(int)validMoves.size();i++) {
        b->applyMove(validMoves.at(i));
        curScore = checkBoardScore(b);
        if (curScore < worstScore) worstScore = curScore;
        b->undoLastMove();
    }
    return worstScore;
}

// getMove - Ai Level 3 looks two steps ahead and implements 
// a point system, choosing the move who's most detrimental counter move
// gives a board with the most points
Move Ai3::getMove(Board* b) {
    vector<Move> validMoves = b->getLegalMoves(!color);
    vector<Move> bestMoves;
    vector<signed int> points;
    signed int bestScore;

    // set the bestScore to be that of the first legal move
    b->applyMove(validMoves.at(0));
    bestScore = checkMostDetrimentalResponseScore(b);
    b->undoLastMove();

    // for every legal move, we check the score of the board after the most
    // detrimental counter, adding it to the score vector
    // and keeping track of the highest score
    for (int i=0;i<(int)validMoves.size();i++) {
        signed int score;
        b->applyMove(validMoves.at(i));
        score = checkMostDetrimentalResponseScore(b);
        b->undoLastMove();

        points.push_back(score);
        if (score > bestScore) bestScore = score;
    }

    // now we create a new vector with only the moves who scored 
    // the highest score
    for(int i=0;i<(int)points.size();i++) {
        if (points.at(i) == bestScore) {
            bestMoves.push_back(validMoves.at(i));
        }
    }

    // return a random move from the vector of best moves
    srand ( time(NULL) );
    int randomNum = rand() % ((int) bestMoves.size());
    return bestMoves.at(randomNum);
}
