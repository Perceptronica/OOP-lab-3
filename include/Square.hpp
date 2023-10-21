// (c) anton perceptronica, 2023

#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle {
protected:
    vector<Point> points;
    double area;
    Point center;
    string type;

    virtual void normalizePoints();
    virtual void calculateArea();
    virtual void calculateCenter();
public:
    Square();
    Square(vector<Point>& _points);
    Square(const Square& other);
    Square(Square&& other) noexcept;

    virtual vector<Point> getPoints() const { return points; };
    virtual Point getCenter() const override{ return center; };
    virtual double getArea() const override{ return area; };
    virtual string getType() const override { return type; };
};