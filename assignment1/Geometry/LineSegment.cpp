#include "LineSegment.h"
#include <fstream>
#include <stdexcept>

LineSegment::LineSegment(const Point2D& startPoint, const Point2D& endPoint)
    : m_start(startPoint), m_end(endPoint)
{
}

std::vector<Point2D> LineSegment::interpolate(int numInnerPoints) const
{
    if (numInnerPoints < 0)
    {
        throw std::invalid_argument("numInnerPoints cannot be negative");
    }

    std::vector<Point2D> points;
    points.reserve(numInnerPoints + 2);

    // total segments = numInnerPoints + 1 (so endpoints land exactly on start/end)
    int totalSteps = numInnerPoints + 1;

    for (int i = 0; i <= totalSteps; ++i)
    {
        double t = static_cast<double>(i) / static_cast<double>(totalSteps);
        double x = m_start.getX() + t * (m_end.getX() - m_start.getX());
        double y = m_start.getY() + t * (m_end.getY() - m_start.getY());
        points.emplace_back(x, y);
    }

    return points;
}

void LineSegment::writeToFile(const std::string& filename, int numInnerPoints) const
{
    std::vector<Point2D> points = interpolate(numInnerPoints);

    std::ofstream outFile(filename);
    if (!outFile.is_open())
    {
        throw std::runtime_error("Could not open file: " + filename);
    }

    for (const Point2D& p : points)
    {
        outFile << p.getX() << " " << p.getY() << "\n";
    }

    outFile.close();
}
