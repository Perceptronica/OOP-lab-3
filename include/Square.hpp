// (c) anton perceptronica, 2023

#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle {
protected:
    vector<Point> points;
    double area;
    Point center;
    string type = "Square";
public:
    Square() = default;
    Square(vector<Point>& _points);
    Square(const Square& other);
    Square(Square&& other) noexcept;

    virtual ~Square() {};
};