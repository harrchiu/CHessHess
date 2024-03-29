#ifndef TEXTUAL_DISPLAY_H
#define TEXTUAL_DISPLAY_H

#include <vector>
#include "Display.h"
#include "State.h"

// class to represent a textual display
class TextualDisplay : public Display {
    public:
        TextualDisplay(int, int);
        void display(State) override;
};

#endif
