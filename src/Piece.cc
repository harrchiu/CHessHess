#include "Piece.h"

// CTOR
Piece::Piece(bool isWhite) : isWhite {isWhite} {};
// DTOR
Piece::~Piece(){};

// getIsWhite - returns if the piece is white
bool Piece::getIsWhite(){ return isWhite; }

// static list of letters that represent the pieces
const char Piece::letters[6] = {'p','r','n','b','q','k'};

double Piece::getPoints(int r, int c) { return 0; }
