#ifndef DISPLAY_H
#define DISPLAY_H

#include "Move.h"
#include "State.h"
#include <vector>

// class to represent displays
class Display {
    protected:
        const int rows, cols;
        std::vector<std::vector<char>> displayGrid;
    public:
        Display(int, int);
        virtual ~Display();
        void setSquare(int, int, PieceType, bool);
        void update(const Move &);
        void restore(const Move &);
        virtual void display(State s) = 0;
};

#endif
