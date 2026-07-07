#ifndef SHAPE_H
#define SHAPE_H

#include <string>

// Abstract base class. Every derived Shape must implement area(), perimeter(),
// and name(). This is the "inheritance" contract that Circle and Rectangle
// (in their own files) plug into.
class Shape
{
public:
    virtual ~Shape() = default;

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string name() const = 0;

    // Shared behavior every Shape gets for free - doesn't need to be
    // reimplemented by each derived class.
    void printSummary() const;
};

#endif // SHAPE_H
