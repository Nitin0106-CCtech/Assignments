#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
public:
    explicit Circle(double radius);

    double area() const override;
    double perimeter() const override;
    std::string name() const override;

private:
    double m_radius;
};

#endif // CIRCLE_H
