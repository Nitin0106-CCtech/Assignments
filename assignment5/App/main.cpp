#include <iostream>
#include "../Geometry/Point2D.h"
#include "../Geometry/Point3D.h"
#include "../Geometry/LineSegment.h"
#include "../Geometry/BezierCurve.h"
#include "../Geometry/Polygon2D.h"
#include "../Geometry/Cuboid.h"

int main()
{
    std::cout << "Assignment 5: Full shape library demo\n";
    std::cout << "======================================\n\n";

    // --- Line segment (from Assignment 1/2) ---
    LineSegment<Point2D> line(Point2D(0.0, 0.0), Point2D(10.0, 5.0));
    line.writeToFile("line.dat", 8);
    std::cout << "Line: wrote line.dat (10 points)\n";

    // --- 2D cubic Bezier curve via de Casteljau ---
    std::vector<Point2D> controlPoints2D = {
        Point2D(0.0, 0.0),
        Point2D(2.0, 8.0),
        Point2D(6.0, -4.0),
        Point2D(10.0, 4.0)
    };
    BezierCurve<Point2D> bezier2D(controlPoints2D);
    bezier2D.writeToFile("bezier2d.dat", 50);
    std::cout << "2D Bezier: wrote bezier2d.dat (51 points along the curve)\n";

    // --- 3D Bezier curve - same class, same algorithm, one more dimension ---
    std::vector<Point3D> controlPoints3D = {
        Point3D(0.0, 0.0, 0.0),
        Point3D(2.0, 8.0, 3.0),
        Point3D(6.0, -4.0, 6.0),
        Point3D(10.0, 4.0, 9.0)
    };
    BezierCurve<Point3D> bezier3D(controlPoints3D);
    bezier3D.writeToFile("bezier3d.dat", 50);
    std::cout << "3D Bezier: wrote bezier3d.dat (51 points along the curve)\n";

    // --- 2D polygon: a simple pentagon ---
    std::vector<Point2D> pentagonVertices = {
        Point2D(0.0, 2.0),
        Point2D(1.9, 0.6),
        Point2D(1.2, -1.6),
        Point2D(-1.2, -1.6),
        Point2D(-1.9, 0.6)
    };
    Polygon2D pentagon(pentagonVertices);
    pentagon.writeToFile("polygon.dat");
    std::cout << "Polygon: wrote polygon.dat\n";
    std::cout << "  perimeter = " << pentagon.perimeter() << "\n";
    std::cout << "  area      = " << pentagon.area() << "\n";

    // --- 3D solid: a cuboid ---
    Cuboid box(4.0, 3.0, 2.0);
    box.writeVerticesToFile("cuboid_vertices.dat");
    std::cout << "Cuboid: wrote cuboid_vertices.dat (8 vertices)\n";
    std::cout << "  volume       = " << box.volume() << "\n";
    std::cout << "  surface area = " << box.surfaceArea() << "\n\n";

    std::cout << "Plot commands:\n";
    std::cout << "  gnuplot -e \"plot 'line.dat' with linespoints; pause -1\"\n";
    std::cout << "  gnuplot -e \"plot 'bezier2d.dat' with lines, 'line.dat' with points; pause -1\"\n";
    std::cout << "  gnuplot -e \"splot 'bezier3d.dat' with lines; pause -1\"\n";
    std::cout << "  gnuplot -e \"plot 'polygon.dat' with linespoints; pause -1\"\n";
    std::cout << "  gnuplot -e \"splot 'cuboid_vertices.dat' with points pointsize 2; pause -1\"\n";

    return 0;
}
