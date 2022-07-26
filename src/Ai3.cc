#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Ai3.h"
#include "Move.h"

using namespace std;

Ai3::Ai3(PieceColour p) : Player{p} {}

signed int Ai3::checkBoardScore(Board* b) {
    signed int score = 0;
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
                if (pp->getIsWhite() == !color) { //true = 1 = Black its reversed
                    score = score + pieceScore;
                } else {
                    score = score - pieceScore;
                }
            }
        }
    }
    if (b->isCheck(!color,false)) {
        score += 1.0;
    } if (b->isCheck(color,false)) {
        score -= 1.0;
    }
    return score;
}

signed int Ai3::checkMostDetrimentalResponseScore(Board* b) {
    vector<Move> validMoves = b->getLegalMoves(color);
    signed int worstScore;
    signed int curScore;

    if (validMoves.empty()){
        if (b->isCheck(color)){
            return 9000; 
        }
        else{
            return 0;
        }
    }

    b->applyMove(validMoves.at(0));
    worstScore = checkBoardScore(b);
    b->undoLastMove();

    for(int i=0;i<(int)validMoves.size();i++) {
        b->applyMove(validMoves.at(i));
        curScore = checkBoardScore(b);
        if (curScore < worstScore) worstScore = curScore;
        b->undoLastMove();

        // cout << validMoves.at(i) << curScore << "\n";;

    }
    return worstScore;
}

Move Ai3::getMove(Board* b) {
    vector<Move> validMoves = b->getLegalMoves(!color);
    vector<Move> bestMoves;
    vector<signed int> points;
    signed int bestScore;

    b->applyMove(validMoves.at(0));
    bestScore = checkMostDetrimentalResponseScore(b);
    // bestScore = checkBoardScore(b);
    b->undoLastMove();

    for (int i=0;i<(int)validMoves.size();i++) {
        signed int score;
        b->applyMove(validMoves.at(i));
        score = checkMostDetrimentalResponseScore(b);
        // score = checkBoardScore(b);
        b->undoLastMove();

        // cout << validMoves.at(i) << " Max score: " << score << "\n";
        points.push_back(score);
        if (score > bestScore) bestScore = score;
    }

    for(int i=0;i<(int)points.size();i++) {
        if (points.at(i) == bestScore) {
            bestMoves.push_back(validMoves.at(i));
        }
    }

    srand ( time(NULL) );
    int randomNum = rand() % ((int) bestMoves.size());
    return bestMoves.at(randomNum);
}
