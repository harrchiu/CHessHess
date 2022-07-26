#ifndef GRAPHICAL_DISPLAY_H
#define GRAPHICAL_DISPLAY_H

#include "Display.h"
#include "State.h"

class GraphicalDisplay : public Display {
    public:
        GraphicalDisplay(int, int);
        
        void update(const Move &) override;
        void display(State) override;
        void setSquare(int, int, PieceType, bool) override;
        void restore(const Move &) override;
};

#endif
