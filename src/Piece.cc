#include "Piece.h"

Piece::Piece(bool isWhite) : isWhite {isWhite} {};
Piece::~Piece(){};

bool Piece::getIsWhite(){ return isWhite; }
