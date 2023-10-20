// (c) anton perceptronica, 2023

#pragma once

#include "Figure.hpp"
#include "Point.hpp"

class Rectangle : public Figure {
protected:
    vector<Point> points;
    Point center;
    double area;

    virtual Point calculateCenter(const vector<Point> & _points) const override;
    virtual double calculateArea(const vector<Point> & _points) const override;
public:
    Rectangle();
    Rectangle(vector<Point> & _points);
    Rectangle(vector<Point> && _points);
    Rectangle(const Rectangle & other);
    Rectangle(Rectangle && other) noexcept;

    friend ostream &operator<<(ostream &out, const Rectangle &rct);
    friend istream &operator>>(istream &in, const Rectangle &rct);

    virtual vector<Point> getPoints() const;
};