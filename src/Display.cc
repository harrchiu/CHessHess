#include "Display.h"

using namespace std;

// CTOR
Display::Display(int rows, int cols) : rows{rows}, cols{cols}, displayGrid{vector<vector<char>>()} {
    for (auto i = 0; i < rows; ++i) {
        displayGrid.emplace_back();
        for (auto j = 0; j < cols; ++j) {
            displayGrid[i].push_back((i + j) % 2 == 0 ? ' ' : '_');
        }
    }
}

// DTOR
Display::~Display() {}

void Display::setSquare(int r, int c, PieceType p, bool isWhite) {
    if (p == PieceType::EMPTY) {
        displayGrid[r][c] = (r + c) % 2 == 0 ? ' ' : '_';
    } else {
        char piece = Piece::letters[p];
        displayGrid[r][c] = isWhite ? static_cast<char>(toupper(piece)) : piece;
    }
}

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
