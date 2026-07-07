#ifndef POINT3D_H
#define POINT3D_H

#include "Point2D.h"

// Inherits x, y (and their getters/setters) from Point2D. Only z is new.
class Point3D : public Point2D
{
public:
    Point3D();
    Point3D(double xCoord, double yCoord, double zCoord);
    explicit Point3D(const std::vector<double>& coords);

    double getZ() const;
    void setZ(double zCoord);

    std::vector<double> getCoordinates() const override;

private:
    double m_z;
};

#endif // POINT3D_H
