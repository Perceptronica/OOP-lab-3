// (c) anton perceptronica, 2023

// (c) anton perceptronica, 2023

#include "Square.hpp"
#include <vector>
#include "Point.hpp"

Square::Square(vector<Point>& _points) : Square(){
    points.reserve(_points.size());
    points = _points;
    type = "square";
    calculateCenter();
    normalizePoints();
    SquareValidator::validate(points);
    calculateArea();
}

Square::Square(const Square& other) : Square(){
    points.reserve(other.points.size());
    points = other.points;
    center = other.center;
    area = other.area;
    type = other.type;
}

Square::Square(Square&& other) noexcept : Square(){
    points.reserve(other.points.size());
    points = other.points;
    center = other.center;
    area = other.area;
    type = other.type;
    delete& other;
}