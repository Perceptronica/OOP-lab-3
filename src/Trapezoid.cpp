// (c) anton perceptronica, 2023

// (c) anton perceptronica, 2023

#include "Trapezoid.hpp"
#include <vector>
#include "Point.hpp"

Trapezoid::Trapezoid(vector<Point>& _points) : Trapezoid(){
    points.reserve(_points.size());
    points = _points;
    type = "Trapezoid";
    calculateCenter();
    normalizePoints();
    TrapezoidValidator::validate(points);
    calculateArea();
}

Trapezoid::Trapezoid(const Trapezoid& other) : Trapezoid(){
    points.reserve(other.points.size());
    points = other.points;
    center = other.center;
    area = other.area;
    type = other.type;
}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept : Trapezoid(){
    points.reserve(other.points.size());
    points = other.points;
    center = other.center;
    area = other.area;
    type = other.type;
    delete& other;
}