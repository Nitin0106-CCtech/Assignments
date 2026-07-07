#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include <vector>
#include <string>
#include "Point2D.h"

class LineSegment
{
public:
    LineSegment(const Point2D& startPoint, const Point2D& endPoint);

    // Returns startPoint, numInnerPoints interpolated points, then endPoint (numInnerPoints + 2 total)
    std::vector<Point2D> interpolate(int numInnerPoints) const;

    // Runs interpolate() and writes the result to a .dat file (space separated, gnuplot-friendly)
    void writeToFile(const std::string& filename, int numInnerPoints) const;

private:
    Point2D m_start;
    Point2D m_end;
};

#endif // LINESEGMENT_H
