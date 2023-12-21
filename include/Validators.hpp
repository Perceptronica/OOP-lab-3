// (c) anton perceptronica, 2023

#pragma once

#include "Figure.hpp"
#include <vector>

bool isConvex(const vector<Point>& _points);
int getOrientation(const Point& p1, const Point& p2, const Point& p3);
bool isSquare(const vector<Point>& _points);
bool isRectangle(const vector<Point>& _points);
bool PointsCoincide(const vector<Point>& _points);

class Validator {
public:
    static void validate(const vector<Point>& _points);
};

class RectangleValidator : public Validator {
public:
    static void validate(const vector<Point>& _points);
};

class SquareValidator : public Validator {
public:
    static void validate(const vector<Point>& _points);
};

class TrapezoidValidator : public Validator {
public:
    static void validate(const vector<Point>& _points);
};