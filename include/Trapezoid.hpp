// (c) anton perceptronica, 2023

#pragma once

#include "Figure.hpp"

class Trapezoid : public Figure {
protected:
    vector<Point> points;
    double area;
    Point center;
    string type = "Trapezoid";
public:
    Trapezoid() = default;
    Trapezoid(vector<Point>& _points);
    Trapezoid(const Trapezoid& other);
    Trapezoid(Trapezoid&& other) noexcept;
    
    virtual ~Trapezoid() {};
};