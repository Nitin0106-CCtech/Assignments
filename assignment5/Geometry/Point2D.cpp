#include "Point2D.h"
#include <stdexcept>

Point2D::Point2D()
    : m_x(0.0), m_y(0.0)
{
}

Point2D::Point2D(double xCoord, double yCoord)
    : m_x(xCoord), m_y(yCoord)
{
}

Point2D::Point2D(const std::vector<double>& coords)
{
    if (coords.size() < 2)
    {
        throw std::invalid_argument("Point2D needs at least 2 coordinates");
    }
    m_x = coords[0];
    m_y = coords[1];
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

std::vector<double> Point2D::getCoordinates() const
{
    return { m_x, m_y };
}
