#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Ai2.h"
#include "Move.h"

using namespace std;

Ai2::Ai2(PieceColour p) : Player{p} {}

Move Ai2::getMove(Board* b){
    vector<Move> validMoves = b->getLegalMoves(!color);
    vector<Move> captures;
    vector<Move> checks;
    for(int i=0;i<(int)validMoves.size();i++) {
        if (validMoves.at(i).capturedPiece != PieceType::EMPTY) {
            captures.push_back(validMoves.at(i));
        }
        
        b->applyMove(validMoves.at(i));
        if (color == PieceColour::WHITE) {
            if (b->isCheck(false,false)) {
                checks.push_back(validMoves.at(i));
            }
        } else {
            if (b->isCheck(true,false)) {
                checks.push_back(validMoves.at(i));
            }
        }
        b->undoLastMove();
    }

    if (!captures.empty()) {
        int randomNum = rand() % (int) captures.size();
        return captures.at(randomNum);
    }

    if (!checks.empty()) {
        int randomNum = rand() % (int) checks.size();
        return checks.at(randomNum);
    }

    srand ( time(NULL) );
    int randomNum = rand() % ((int) validMoves.size());
    return validMoves.at(randomNum);
}
