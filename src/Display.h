#ifndef DISPLAY_H
#define DISPLAY_H

#include "Board.h"

class Display {
    protected:
        Board* board;        
    public:
        Display(Board*);
        ~Display();
        virtual void update() = 0;
        virtual void display() = 0;
};

#endif
