// (c) anton perceptronica, 2023
// определяю отрезок

#pragma once

#include "Point.hpp"
#include <stdexcept>

#ifndef SEGMENT_HPP
#define SEGMENT_HPP

class Segment {
private:
    Point r1;
    Point r2;
    Point dr;

public:
    Segment(Point r1, Point r2);
    
    Point getR1() const;
    Point getR2() const;
    Point getDR() const;

    bool operator||(const Segment & rhs) const;
    double length() const;
};

double operator*(const Segment & s1, const Segment & s2);
double operator^(const Segment & s1, const Segment & s2);

#endif