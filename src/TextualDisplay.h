#ifndef TEXTUAL_DISPLAY_H
#define TEXTUAL_DISPLAY_H

#include <vector>
#include "Display.h"
#include "State.h"

// class to represent a textual display
class TextualDisplay : public Display {
    std::vector<std::vector<char>> displayGrid;

    public:
        TextualDisplay(int, int);
        
        void setSquare(int, int, PieceType, bool) override;
        void update(const Move &) override;
        void restore(const Move &) override;
        void display(State) override;
};

#endif
