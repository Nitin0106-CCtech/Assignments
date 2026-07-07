#ifndef POINT2D_H
#define POINT2D_H

#include <vector>

class Point2D
{
public:
    Point2D();
    Point2D(double xCoord, double yCoord);
    explicit Point2D(const std::vector<double>& coords); // needed so the templated LineSegment can build points generically
    virtual ~Point2D() = default;

    double getX() const;
    double getY() const;

    void setX(double xCoord);
    void setY(double yCoord);

    // Returns {x, y}. Point3D overrides this to return {x, y, z}.
    // This is the "minimum change" hook that lets LineSegment work in both 2D and 3D.
    virtual std::vector<double> getCoordinates() const;

protected:
    double m_x;
    double m_y;
};

#endif // POINT2D_H
