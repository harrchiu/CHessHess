#ifndef GRAPHICAL_DISPLAY_H
#define GRAPHICAL_DISPLAY_H

#include "Display.h"
#include "State.h"
#include "sdl_wrap.h"

//class to represent a graphical display
class GraphicalDisplay : public Display {
    int w, h, mh;
    int dw, dh;
    Screen screen;

    public:
        GraphicalDisplay(int, int);
        void setSquare(int, int, PieceType, bool) override;
        void display(State) override;
};

#endif
