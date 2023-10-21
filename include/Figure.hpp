// (c) anton perceptronica, 2023

#pragma once

#include "Point.hpp"
#include "Segment.hpp"
#include "Validators.hpp"
#include <vector>
#include <algorithm>

class Figure {
protected:
    vector<Point> points;
    double area;
    Point center;
    string type;
    //Validator validator = default;

    virtual void normalizePoints();
    virtual void calculateArea();
    virtual void calculateCenter();

public:
    Figure(vector<Point>& _points);
    Figure(const Figure& other);
    Figure(Figure&& other) noexcept;
    Figure operator=(const Figure& other);
    Figure operator=(Figure&& other) noexcept;

    ~Figure() = default;
    
    virtual vector<Point> getPoints() const { return points; };
    virtual Point getCenter() const { return center; };
    virtual double getArea() const { return area; };
    virtual string getType() const { return type; };
};

ostream& operator<<(ostream& out, const Figure& f);