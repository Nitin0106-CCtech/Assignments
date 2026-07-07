#include "Point2D.h"

Point2D::Point2D()
    : m_x(0.0), m_y(0.0)
{
}

Point2D::Point2D(double xCoord, double yCoord)
    : m_x(xCoord), m_y(yCoord)
{
}

double Point2D::getX() const
{
    return m_x;
}

double Point2D::getY() const
{
    return m_y;
}

void Point2D::setX(double xCoord)
{
    m_x = xCoord;
}

void Point2D::setY(double yCoord)
{
    m_y = yCoord;
}
