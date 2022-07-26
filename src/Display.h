#ifndef DISPLAY_H
#define DISPLAY_H

#include "Move.h"

class Display {
    protected:
        const int rows, cols;      
    public:
        Display(int, int);
        virtual ~Display();
        virtual void setSquare(int, int, PieceType, bool) = 0;
        virtual void update(const Move &) = 0;
        virtual void display(State s) = 0;
};

#endif
