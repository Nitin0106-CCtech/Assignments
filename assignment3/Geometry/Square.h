#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

// Square IS-A Rectangle (multi-level inheritance: Shape -> Rectangle -> Square).
// Only needs to constrain width == height and override name().
class Square : public Rectangle
{
public:
    explicit Square(double side);

    std::string name() const override;
};

#endif // SQUARE_H
