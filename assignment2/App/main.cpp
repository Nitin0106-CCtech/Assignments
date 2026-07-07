#include <iostream>
#include "../Geometry/Point2D.h"
#include "../Geometry/Point3D.h"
#include "../Geometry/LineSegment.h"

int main()
{
    // 2D case - identical behavior to Assignment 1
    Point2D start2D(0.0, 0.0);
    Point2D end2D(10.0, 5.0);
    LineSegment<Point2D> segment2D(start2D, end2D);
    segment2D.writeToFile("output2d.dat", 8);
    std::cout << "2D: wrote output2d.dat (10 points)\n";

    // 3D case - same LineSegment template, no new interpolation code written
    Point3D start3D(0.0, 0.0, 0.0);
    Point3D end3D(10.0, 5.0, 3.0);
    LineSegment<Point3D> segment3D(start3D, end3D);
    segment3D.writeToFile("output3d.dat", 8);
    std::cout << "3D: wrote output3d.dat (10 points)\n";

    std::cout << "\nPlot 2D: gnuplot -e \"plot 'output2d.dat' with linespoints; pause -1\"\n";
    std::cout << "Plot 3D: gnuplot -e \"splot 'output3d.dat' with linespoints; pause -1\"\n";

    return 0;
}
