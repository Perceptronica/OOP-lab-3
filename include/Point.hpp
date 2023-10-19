// (c) anton perceptronica, 2023
// определяю точку

#pragma once

#include <cmath>
#include <vector>

using namespace std;

#ifndef POINT_HPP
#define POINT_HPP

class Point{
private:
    double x;
    double y;

public:
    Point() : x(0), y(0) {};
    Point(double x_, double y_) : x(x_), y(y_) {};
    Point(const Point & other);
    Point(Point && other) noexcept;

    ~Point() = default;

    double getX() const;
    double getY() const;
    double length() const; // длина радиус-вектора

    Point operator+(const Point & rhs) const;
    Point operator-(const Point & rhs) const;

    Point operator=(const Point & rhs);
    Point operator=(Point && rhs); 

    bool operator==(const Point & rhs) const;
};

// так как точка дает радиус-вектор, то можем определить произведения:
double operator*(const Point & r1, const Point & r2); // скалярное
double operator^(const Point & r1, const Point & r2); // векторное

#endif