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
        virtual void setSquare(int, int, PieceType, bool) = 0;
        void update(const Move &);
        void restore(const Move &);
        virtual void display(State s) = 0;
};

#endif
