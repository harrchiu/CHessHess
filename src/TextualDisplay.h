#ifndef TEXTUAL_DISPLAY_H
#define TEXTUAL_DISPLAY_H

#include <vector>
#include "Display.h"
#include "State.h"

class TextualDisplay : public Display {
    std::vector<std::vector<char>> displayGrid;

    public:
        TextualDisplay(int, int);
        void setSquare(int, int, PieceType, bool) override;
        void display(State) override;
};

#endif
