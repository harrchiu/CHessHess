#include "Piece.h"

Piece::Piece(bool isWhite) : isWhite {isWhite} {};
Piece::~Piece(){};

bool Piece::getIsWhite(){ return isWhite; }

const char Piece::letters[6] = {'p','r','n','b','q','k'};

double Piece::getPoints(int r, int c) { return 0; }
