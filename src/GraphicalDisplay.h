#ifndef GRAPHICAL_DISPLAY_H
#define GRAPHICAL_DISPLAY_H

#include "Display.h"
#include "State.h"
#include "sdl_wrap.h"

//class to represent a graphical display
class GraphicalDisplay : public Display {
    int w, h;
    int rankw, fileh, messageh;
    int dw, dh;
    Screen screen;

    public:
        GraphicalDisplay(int, int);
        void display(State) override;
};

#endif
