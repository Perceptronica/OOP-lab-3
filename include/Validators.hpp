// (c) anton perceptronica, 2023

#pragma once

#include "Figure.hpp"
#include <vector>

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

class Trapezoid : public Validator {
public:
    static void validate(const vector<Point>& _points);
}