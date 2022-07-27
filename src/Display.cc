#include "Display.h"

// CTOR
Display::Display(int rows, int cols) : rows{rows}, cols{cols} {}

// DTOR
Display::~Display() {}

void Display::update(const Move &m) {
    // special cases
    if (m.moveType == MoveType::CASTLE_Q_SIDE) {
        setSquare(m.start.first, 3, PieceType::ROOK, m.isSideWhite);
        setSquare(m.start.first, 0, PieceType::EMPTY, m.isSideWhite);
    } else if (m.moveType == MoveType::CASTLE_K_SIDE) {
        setSquare(m.start.first, 5, PieceType::ROOK, m.isSideWhite);
        setSquare(m.start.first, 7, PieceType::EMPTY, m.isSideWhite);
    } else if (m.moveType == MoveType::EN_PASSANT) {
        setSquare(m.start.first, m.end.second, PieceType::EMPTY, !m.isSideWhite);
    }

    // update begin and end square
    setSquare(m.end.first, m.end.second, m.piece, m.isSideWhite);
    if (m.moveType == MoveType::PROMOTION) {
        setSquare(m.end.first, m.end.second, m.promotedTo, m.isSideWhite);
    }
    setSquare(m.start.first, m.start.second, PieceType::EMPTY, m.isSideWhite);
}

void Display::restore(const Move &m) {
    // special cases
    if (m.moveType == MoveType::CASTLE_Q_SIDE) {
        setSquare(m.start.first, 3, PieceType::EMPTY, m.isSideWhite);
        setSquare(m.start.first, 0, PieceType::ROOK, m.isSideWhite);
    } else if (m.moveType == MoveType::CASTLE_K_SIDE) {
        setSquare(m.start.first, 5, PieceType::EMPTY, m.isSideWhite);
        setSquare(m.start.first, 7, PieceType::ROOK, m.isSideWhite);
    } else if (m.moveType == MoveType::EN_PASSANT) {
        setSquare(m.start.first, m.end.second, PieceType::PAWN, !m.isSideWhite);
    }

    // restore begin and end square
    setSquare(m.end.first, m.end.second, PieceType::EMPTY, m.isSideWhite);
    setSquare(m.start.first, m.start.second, m.piece, m.isSideWhite);
}
