#include "Square.h"

Square::Square(double side)
    : Rectangle(side, side) // reuses Rectangle's area()/perimeter() as-is
{
}

std::string Square::name() const
{
    return "Square";
}
