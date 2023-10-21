// (c) anton perceptronica, 2023

#pragma once

#include "Figure.hpp"

class Rectangle : public Figure {
protected:
    vector<Point> points;
    double area;
    Point center;
    string type;

    virtual void normalizePoints();
    virtual void calculateArea();
    virtual void calculateCenter();
public:
    Rectangle();
    Rectangle(vector<Point>& _points);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;

    virtual vector<Point> getPoints() const { return points; };
    virtual Point getCenter() const override{ return center; };
    virtual double getArea() const override{ return area; };
    virtual string getType() const override { return type; };
};