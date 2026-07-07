#ifndef POLYGON2D_H
#define POLYGON2D_H

#include <vector>
#include <string>
#include "Point2D.h"

// Any simple (non-self-intersecting) polygon, given as an ordered list of
// vertices. Works for any number of sides >= 3 - no separate Triangle/
// Pentagon/Hexagon classes needed.
class Polygon2D
{
public:
    explicit Polygon2D(const std::vector<Point2D>& vertices);

    double perimeter() const;

    // Shoelace formula: sum of (x_i * y_i+1 - x_i+1 * y_i), take half the
    // absolute value. Works for any simple polygon, convex or not.
    double area() const;

    // Writes vertices in order, then repeats the first vertex at the end,
    // so gnuplot draws a closed loop instead of an open path.
    void writeToFile(const std::string& filename) const;

private:
    std::vector<Point2D> m_vertices;
};

#endif // POLYGON2D_H
