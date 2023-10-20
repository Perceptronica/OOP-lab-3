// (c) anton perceptronica, 2023

#pragma once

#include <iostream>
#include <vector>
#include "Point.hpp"
#include "Segment.hpp"

using namespace std;

#ifndef FIGURE_HPP
#define FIGURE_HPP

class Figure {
protected:
    vector<Point> points; 
    Point center;
    double area;

    virtual Point calculateCenter(const vector<Point> & _points) const;
    virtual double calculateArea(const vector<Point> & _points) const;
public:
    //Figure() = default;
    Figure(const vector<Point> & points);

    virtual vector<Point> getPoints() const;
    virtual Point getCenter() const;
    virtual double getArea() const;

    virtual Figure operator=(const Figure & rhs);
    virtual Figure operator=(Figure && rhs);
    virtual bool operator==(const Figure & rhs) const;

    friend istream& operator>>(istream & in, Figure & figure);
};

ostream& operator<<(ostream & out, const Figure & figure);

#endif