#ifndef TEXTUAL_DISPLAY
#define TEXTUAL_DISPLAY

#include "Display.h"

class TextualDisplay : public Display {
    public:
        void update() override;
        void display() override;
};

#endif