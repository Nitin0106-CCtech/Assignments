#ifndef BEZIERCURVE_H
#define BEZIERCURVE_H

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

// Templated on PointT (Point2D or Point3D - anything with getCoordinates()
// and a PointT(const vector<double>&) constructor, same contract LineSegment
// uses). Any number of control points is supported - de Casteljau's algorithm
// doesn't care whether it's quadratic (3 points), cubic (4 points), or higher.
template <typename PointT>
class BezierCurve
{
public:
    explicit BezierCurve(const std::vector<PointT>& controlPoints)
        : m_controlPoints(controlPoints)
    {
        if (m_controlPoints.size() < 2)
        {
            throw std::invalid_argument("BezierCurve needs at least 2 control points");
        }
    }

    // De Casteljau's algorithm: repeatedly lerp adjacent points until one remains.
    // At t=0 this returns the first control point, at t=1 the last - the curve
    // never actually touches the intermediate control points, only uses them
    // to bend the path.
    PointT evaluate(double t) const
    {
        std::vector<std::vector<double>> working;
        working.reserve(m_controlPoints.size());
        for (const PointT& p : m_controlPoints)
        {
            working.push_back(p.getCoordinates());
        }

        std::size_t n = working.size();
        while (n > 1)
        {
            for (std::size_t i = 0; i + 1 < n; ++i)
            {
                for (std::size_t d = 0; d < working[i].size(); ++d)
                {
                    working[i][d] = (1.0 - t) * working[i][d] + t * working[i + 1][d];
                }
            }
            --n;
        }

        return PointT(working[0]);
    }

    // Samples the curve at numSegments+1 evenly-spaced t values (0 through 1 inclusive).
    std::vector<PointT> sample(int numSegments) const
    {
        if (numSegments < 1)
        {
            throw std::invalid_argument("numSegments must be at least 1");
        }

        std::vector<PointT> points;
        points.reserve(numSegments + 1);
        for (int i = 0; i <= numSegments; ++i)
        {
            double t = static_cast<double>(i) / static_cast<double>(numSegments);
            points.push_back(evaluate(t));
        }
        return points;
    }

    void writeToFile(const std::string& filename, int numSegments) const
    {
        std::vector<PointT> points = sample(numSegments);

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
    std::vector<PointT> m_controlPoints;
};

#endif // BEZIERCURVE_H
