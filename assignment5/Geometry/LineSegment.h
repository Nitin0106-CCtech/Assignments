#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

// Templated on PointT so the exact same class works for Point2D and Point3D
// (or anything else with a getCoordinates() -> vector<double> and a
// PointT(const vector<double>&) constructor). The interpolation math itself
// is unchanged from Assignment 1 - it now just loops over however many
// coordinates PointT reports.
template <typename PointT>
class LineSegment
{
public:
    LineSegment(const PointT& startPoint, const PointT& endPoint)
        : m_start(startPoint), m_end(endPoint)
    {
    }

    std::vector<PointT> interpolate(int numInnerPoints) const
    {
        if (numInnerPoints < 0)
        {
            throw std::invalid_argument("numInnerPoints cannot be negative");
        }

        std::vector<double> startCoords = m_start.getCoordinates();
        std::vector<double> endCoords = m_end.getCoordinates();

        std::vector<PointT> points;
        points.reserve(numInnerPoints + 2);

        int totalSteps = numInnerPoints + 1;
        for (int i = 0; i <= totalSteps; ++i)
        {
            double t = static_cast<double>(i) / static_cast<double>(totalSteps);
            std::vector<double> coords(startCoords.size());
            for (std::size_t d = 0; d < startCoords.size(); ++d)
            {
                coords[d] = startCoords[d] + t * (endCoords[d] - startCoords[d]);
            }
            points.emplace_back(coords);
        }

        return points;
    }

    void writeToFile(const std::string& filename, int numInnerPoints) const
    {
        std::vector<PointT> points = interpolate(numInnerPoints);

        std::ofstream outFile(filename);
        if (!outFile.is_open())
        {
            throw std::runtime_error("Could not open file: " + filename);
        }

        for (const PointT& p : points)
        {
            std::vector<double> c = p.getCoordinates();
            for (std::size_t i = 0; i < c.size(); ++i)
            {
                outFile << c[i];
                if (i + 1 < c.size())
                {
                    outFile << " ";
                }
            }
            outFile << "\n";
        }
    }

private:
    PointT m_start;
    PointT m_end;
};

#endif // LINESEGMENT_H
