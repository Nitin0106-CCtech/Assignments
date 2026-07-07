#ifndef POINT2D_H
#define POINT2D_H

class Point2D
{
public:
    Point2D();
    Point2D(double xCoord, double yCoord);

    double getX() const;
    double getY() const;

    void setX(double xCoord);
    void setY(double yCoord);

private:
    double m_x;
    double m_y;
};

#endif // POINT2D_H
