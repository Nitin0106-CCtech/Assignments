#include "Rectangle.h"

Rectangle::Rectangle(double width, double height)
    : m_width(width), m_height(height)
{
}

double Rectangle::area() const
{
    return m_width * m_height;
}

double Rectangle::perimeter() const
{
    return 2.0 * (m_width + m_height);
}

std::string Rectangle::name() const
{
    return "Rectangle";
}
