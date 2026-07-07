#include "Polygon2D.h"
#include <cmath>
#include <fstream>
#include <stdexcept>

Polygon2D::Polygon2D(const std::vector<Point2D>& vertices)
    : m_vertices(vertices)
{
    if (m_vertices.size() < 3)
    {
        throw std::invalid_argument("Polygon2D needs at least 3 vertices");
    }
}

double Polygon2D::perimeter() const
{
    double total = 0.0;
    std::size_t n = m_vertices.size();

    for (std::size_t i = 0; i < n; ++i)
    {
        const Point2D& a = m_vertices[i];
        const Point2D& b = m_vertices[(i + 1) % n];
        double dx = b.getX() - a.getX();
        double dy = b.getY() - a.getY();
        total += std::sqrt(dx * dx + dy * dy);
    }

    return total;
}

double Polygon2D::area() const
{
    double sum = 0.0;
    std::size_t n = m_vertices.size();

    for (std::size_t i = 0; i < n; ++i)
    {
        const Point2D& a = m_vertices[i];
        const Point2D& b = m_vertices[(i + 1) % n];
        sum += a.getX() * b.getY() - b.getX() * a.getY();
    }

    return std::abs(sum) / 2.0;
}

void Polygon2D::writeToFile(const std::string& filename) const
{
    std::ofstream outFile(filename);
    if (!outFile.is_open())
    {
        throw std::runtime_error("Could not open file: " + filename);
    }

    for (const Point2D& v : m_vertices)
    {
        outFile << v.getX() << " " << v.getY() << "\n";
    }
    // Repeat the first vertex to close the loop for plotting.
    if (!m_vertices.empty())
    {
        outFile << m_vertices[0].getX() << " " << m_vertices[0].getY() << "\n";
    }
}
