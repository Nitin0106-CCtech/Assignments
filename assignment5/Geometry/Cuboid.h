#ifndef CUBOID_H
#define CUBOID_H

#include <vector>
#include <string>
#include "Point3D.h"

// A basic 3D solid: axis-aligned box with one corner at the origin.
class Cuboid
{
public:
    Cuboid(double length, double width, double height);

    double volume() const;
    double surfaceArea() const;

    // The 8 corners of the box, in an order that traces out the 12 edges
    // when connected as (0-1,1-2,2-3,3-0, 4-5,5-6,6-7,7-4, 0-4,1-5,2-6,3-7).
    std::vector<Point3D> vertices() const;

    void writeVerticesToFile(const std::string& filename) const;

private:
    double m_length;
    double m_width;
    double m_height;
};

#endif // CUBOID_H
