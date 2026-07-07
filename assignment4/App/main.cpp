#include <iostream>
#include <vector>
#include <memory>
#include "../Geometry/Shape.h"
#include "../Geometry/Circle.h"
#include "../Geometry/Rectangle.h"
#include "../Geometry/Square.h"

int main()
{
    // Objects of different derived classes, all treated uniformly as Shape*.
    // This is the "objects + inheritance" demo: printSummary() is inherited
    // from Shape, but area()/perimeter()/name() dispatch to whichever derived
    // class the object actually is (runtime polymorphism via virtual functions).
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(std::make_unique<Square>(3.0));

    std::cout << "Shape hierarchy demo (Makefile-driven multifile build)\n";
    std::cout << "--------------------------------------------------------\n";

    for (const auto& shapePtr : shapes)
    {
        shapePtr->printSummary();
    }

    return 0;
}
