#ifndef DISPLAY_H
#define DISPLAY_H

#include "Move.h"
#include "State.h"

class Display {
    protected:
        const int rows, cols;      
    public:
        Display(int, int);
        virtual ~Display();

        virtual void update(const Move &) = 0;
        virtual void display(State s) = 0;
        virtual void setSquare(int, int, PieceType, bool) = 0;
        virtual void restore(const Move &) = 0;
};

#endif
