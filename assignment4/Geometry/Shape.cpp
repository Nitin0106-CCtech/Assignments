#include "Shape.h"
#include <iostream>

void Shape::printSummary() const
{
    std::cout << name()
              << " -> area = " << area()
              << ", perimeter = " << perimeter()
              << "\n";
}
