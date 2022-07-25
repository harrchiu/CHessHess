#ifndef TEXTUAL_DISPLAY_H
#define TEXTUAL_DISPLAY_H

#include "Display.h"

class TextualDisplay : public Display {
    public:
        void update() override;
        void display() override;
};

#endif