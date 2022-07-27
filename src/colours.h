#ifndef COLOURS_H
#define COLOURS_H

#include "sdl_wrap.h"

extern const Colour Black{static_cast<unsigned char>('\x0'), static_cast<unsigned char>('\x0'), static_cast<unsigned char>('\x0')};
extern const Colour Blue{static_cast<unsigned char>('\x0'), static_cast<unsigned char>('\x0'), static_cast<unsigned char>('\xff')};
extern const Colour Gray{static_cast<unsigned char>('\x0'), static_cast<unsigned char>('\x80'), static_cast<unsigned char>('\x80')};
extern const Colour Green{static_cast<unsigned char>('\x0'), static_cast<unsigned char>('\x80'), static_cast<unsigned char>('\x0')};
extern const Colour Purple{static_cast<unsigned char>('\x80'), static_cast<unsigned char>('\x0'), static_cast<unsigned char>('\x80')};
extern const Colour Red{static_cast<unsigned char>('\xff'), static_cast<unsigned char>('\x0'), static_cast<unsigned char>('\x0')};
extern const Colour White{static_cast<unsigned char>('\xff'),static_cast<unsigned char>('\xff'),static_cast<unsigned char>('\xff')};

#endif
