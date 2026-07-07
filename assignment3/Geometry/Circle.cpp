#include "Circle.h"
#include <cmath>

Circle::Circle(double radius)
    : m_radius(radius)
{
}

double Circle::area() const
{
    return M_PI * m_radius * m_radius;
}

double Circle::perimeter() const
{
    return 2.0 * M_PI * m_radius;
}

std::string Circle::name() const
{
    return "Circle";
}
