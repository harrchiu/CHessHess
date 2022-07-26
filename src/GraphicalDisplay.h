#ifndef GRAPHICAL_DISPLAY_H
#define GRAPHICAL_DISPLAY_H

#include "Display.h"

class GraphicalDisplay : public Display {
    public:
        GraphicalDisplay(int, int);
        void setSquare(int, int, PieceType, bool) override;
        void update(const Move &) override;
        void display() override;
};

#endif