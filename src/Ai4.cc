#include <iostream>
#include <vector>

#include "Ai4.h"
#include "Move.h"

using namespace std;

const int init_depth = 4;

//CTOR
Ai4::Ai4(PieceColour p) : Player{p} {}

// evaluate the board with a numeric value
// + is winning for white, - is winning for black, ~0 is equal
double evalBoard(Board* b){
    double score = 0;

    for (int r=0;r<(int)b->getBoard().size();++r){
        for (int c=0;c<(int)b->getBoard().at(r).size();++c){
            Piece* pp = b->getBoard().at(r).at(c).piece.get();
            if (pp == nullptr) continue;
            
            // give coordinates so piece can polymorphically determine
            // its value using its board position
            score += pp->getPoints(r, c);
        }
    }
    return score;
}

// min-max algorithm depending on side to move
double getMoveScore(Board*b, bool isWhiteToMove, int depth){
    if (depth <= 1)
        return evalBoard(b);

    double best = isWhiteToMove ? -90000 : 90000;

    vector<Move> legalMoves = b->getLegalMoves(isWhiteToMove);
    for (Move m:legalMoves){
        b->applyMove(m);

        if (isWhiteToMove)
            best = max(best,getMoveScore(b,!isWhiteToMove,depth-1));
        else
            best = min(best,getMoveScore(b,!isWhiteToMove,depth-1));

        b->undoLastMove();
    }
    return best;
}

// play every move and use min-max algorithm to determine which is best
Move Ai4::getMove(Board* b, bool isWhiteToMove){
    vector<Move> legalMoves = b->getLegalMoves(isWhiteToMove);
    vector<double> scores;
    double bestScore = isWhiteToMove ? -900000 : 900000;

    // iterate through all our legal moves and look forward by constant depth
    // store the score to its corresponding move in array
    for (Move m:legalMoves){
        b->applyMove(m);
        scores.push_back(getMoveScore(b,!isWhiteToMove,init_depth-1));
        b->undoLastMove();
        if (isWhiteToMove)
            bestScore = max(bestScore, scores.back());
        else
            bestScore = min(bestScore, scores.back());
    }

    // find the move that has the best score
    for (int i=0;i<(int)scores.size();++i){
        if (abs(scores[i] - bestScore) < 0.01){ // address float error
            return legalMoves[i];
        }
    }

    return legalMoves[0];
}
