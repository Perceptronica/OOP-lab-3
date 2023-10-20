// (c) anton perceptronica, 2023

#include "Point.hpp"

class Segment {
private:
    Point r1;
    Point r2;
    Point dr; // отрезок-вектор от начала
              // координат
public:
    Segment(): r1(Point(0, 0)), r2(Point(0, 0)) {};
    Segment(Point r1_, Point r2_): r1(r1_), r2(r2_) {};

    Segment(const Segment& other): r1(other.r1), r2(other.r2) {};
    Segment(Segment&& other) noexcept;
    Segment operator=(const Segment& other);
    Segment operator=(Segment&& other);

    ~Segment() = default;

    Point getR1() const;
    Point getR2() const;
    Point getDR() const;
};