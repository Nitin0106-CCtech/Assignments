#include "Point3D.h"
#include <stdexcept>

Point3D::Point3D()
    : Point2D(), m_z(0.0)
{
}

Point3D::Point3D(double xCoord, double yCoord, double zCoord)
    : Point2D(xCoord, yCoord), m_z(zCoord)
{
}

Point3D::Point3D(const std::vector<double>& coords)
    : Point2D(std::vector<double>{ coords.size() > 0 ? coords[0] : 0.0,
                                    coords.size() > 1 ? coords[1] : 0.0 })
{
    if (coords.size() < 3)
    {
        throw std::invalid_argument("Point3D needs 3 coordinates");
    }
    m_z = coords[2];
}

double Point3D::getZ() const
{
    return m_z;
}

void Point3D::setZ(double zCoord)
{
    m_z = zCoord;
}

std::vector<double> Point3D::getCoordinates() const
{
    return { getX(), getY(), m_z };
}
