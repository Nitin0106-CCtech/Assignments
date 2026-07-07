#include "Cuboid.h"
#include <fstream>
#include <stdexcept>

Cuboid::Cuboid(double length, double width, double height)
    : m_length(length), m_width(width), m_height(height)
{
    if (length <= 0.0 || width <= 0.0 || height <= 0.0)
    {
        throw std::invalid_argument("Cuboid dimensions must be positive");
    }
}

double Cuboid::volume() const
{
    return m_length * m_width * m_height;
}

double Cuboid::surfaceArea() const
{
    return 2.0 * (m_length * m_width + m_width * m_height + m_height * m_length);
}

std::vector<Point3D> Cuboid::vertices() const
{
    return {
        Point3D(0.0, 0.0, 0.0),                          // 0
        Point3D(m_length, 0.0, 0.0),                      // 1
        Point3D(m_length, m_width, 0.0),                  // 2
        Point3D(0.0, m_width, 0.0),                       // 3
        Point3D(0.0, 0.0, m_height),                       // 4
        Point3D(m_length, 0.0, m_height),                  // 5
        Point3D(m_length, m_width, m_height),              // 6
        Point3D(0.0, m_width, m_height)                    // 7
    };
}

void Cuboid::writeVerticesToFile(const std::string& filename) const
{
    std::ofstream outFile(filename);
    if (!outFile.is_open())
    {
        throw std::runtime_error("Could not open file: " + filename);
    }

    for (const Point3D& v : vertices())
    {
        outFile << v.getX() << " " << v.getY() << " " << v.getZ() << "\n";
    }
}
