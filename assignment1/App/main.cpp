#include <iostream>
#include "../Geometry/Point2D.h"
#include "../Geometry/LineSegment.h"

int main(int argc, char* argv[])
{
    // Default endpoints and interpolation count; can be overridden via CLI args.
    double x1 = 0.0, y1 = 0.0;
    double x2 = 10.0, y2 = 5.0;
    int numInnerPoints = 8;

    if (argc == 6)
    {
        x1 = std::stod(argv[1]);
        y1 = std::stod(argv[2]);
        x2 = std::stod(argv[3]);
        y2 = std::stod(argv[4]);
        numInnerPoints = std::stoi(argv[5]);
    }
    else if (argc != 1)
    {
        std::cout << "Usage: " << argv[0]
                  << " [x1 y1 x2 y2 numInnerPoints]\n"
                  << "Running with default values instead.\n";
    }

    Point2D start(x1, y1);
    Point2D end(x2, y2);
    LineSegment segment(start, end);

    const std::string outputFile = "output.dat";
    segment.writeToFile(outputFile, numInnerPoints);

    std::cout << "Interpolated " << numInnerPoints << " points between ("
              << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ")\n";
    std::cout << "Written to " << outputFile << "\n";
    std::cout << "Plot it with gnuplot:\n";
    std::cout << "  gnuplot -e \"plot '" << outputFile
              << "' with linespoints; pause -1\"\n";

    return 0;
}
