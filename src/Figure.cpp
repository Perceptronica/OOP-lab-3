// (c) anton perceptronica, 2023

#include "Figure.hpp"

Figure::Figure(const vector <Point> & _points):
    points(_points), area(0), center(0, 0) {}

vector <Point> Figure::getPoints() const { return points; }

Point Figure::getCenter() const { return center; }

double Figure::getArea() const { return area; }
