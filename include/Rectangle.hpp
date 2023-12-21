// (c) anton perceptronica, 2023

#pragma once

#include "Figure.hpp"

class Rectangle : public Figure {
protected:
    vector<Point> points;
    double area;
    Point center;
    string type = "Rectangle";
public:
    Rectangle() = default;
    Rectangle(vector<Point>& _points);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;

    virtual ~Rectangle() {};
};