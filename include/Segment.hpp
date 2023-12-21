// (c) anton perceptronica, 2023

#pragma once

#include "Point.hpp"
#include <stdexcept>

class Segment {
private:
    Point r1;
    Point r2;
    Point dr; // отрезок-вектор от начала
              // координат
public:
    // дефолтного отрезка нет.
    Segment(Point r1_, Point r2_);

    Segment(const Segment& other): r1(other.r1), r2(other.r2) {};
    Segment(Segment&& other) noexcept;
    Segment operator=(const Segment& other);
    Segment operator=(Segment&& other);

    ~Segment() = default;

    Point getR1() const { return r1; };
    Point getR2() const { return r2; };
    Point getDR() const { return dr; };
    
    bool operator||(const Segment& other) const; // parallel
    bool operator%(const Segment& other) const;  // 90 grad
    double length() const { return dr.length(); };
};

double operator*(const Segment& s1, const Segment& s2);
double operator^(const Segment& s1, const Segment& s2);

double angle(const Segment& s1, const Segment& s2);