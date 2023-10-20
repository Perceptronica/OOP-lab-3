// (c) anton perceptronica, 2023

#include "Validators.hpp"
#include "Point.hpp"
#include "Segment.hpp"
#include "GeometryAlgo.hpp"
#include "Constants.hpp"

void FigureValidator::validate(vector<Point> & _points) const {
    if (_points.size() != 4) {
        throw logic_error("The amount of points does not \
                            allow creating a figure");
    }
    vector <Point> r = Graham(_points);
    if (r.size() != 4) {
        throw logic_error("The input figure is not convex");
    }
}

void RectangleValidator::validate(vector<Point> & _points) const {
    if (_points.size() != 4) {
        throw logic_error("Rectangle must have only 4 points");
    }
    _points = Graham(_points);
    vector<Segment> s;
    for (int i = 0; i < _points.size(); ++i) {
        s.push_back(Segment(_points[i], _points[(i + 1) % _points.size()]));
    }
    if (!(abs(s[0] ^ s[2]) < EPS && 
          abs(s[1] ^ s[3]) < EPS &&
          abs(s[0] ^ s[1]) > 1 - EPS &&
          abs(s[0] ^ s[1]) < 1 + EPS &&
          abs(s[1] ^ s[2]) > 1 - EPS &&
          abs(s[1] ^ s[2]) < 1 + EPS &&
          abs(s[2] ^ s[3]) > 1 - EPS &&
          abs(s[2] ^ s[3]) < 1 + EPS &&
          abs(s[3] ^ s[0]) > 1 - EPS &&
          abs(s[3] ^ s[0]) < 1 + EPS)) {
        throw logic_error("The figure is not a rectangle");
    }
}

void SquareValidator::validate(vector<Point> & _points) const {
    if (_points.size() != 4) {
        throw logic_error("Square must have only 4 points");
    }
    _points = Graham(_points);
    //...
}

void TrapezoidValidator::validate(vector<Point> & _points) const {
    if (_points.size() != 4) {
        throw logic_error("Trapezoid must have only 4 points");
    }
    _points = Graham(_points);
    //...
}