#include "Board.h"

class Display {
    Board* board;        
    public:
        Display(Board*);
        ~Display();
        virtual void update() = 0;
        virtual void display() = 0;
};

