// (c) anton perceptronica, 2023

#include "Rectangle.hpp"
#include <vector>
#include "Point.hpp"

Rectangle::Rectangle(vector<Point>& _points) : Rectangle(){
    points.reserve(_points.size());
    points = _points;
    type = "rectangle";
    calculateCenter();
    normalizePoints();
    RectangleValidator::validate(points);
    calculateArea();
}

Rectangle::Rectangle(const Rectangle& other) : Rectangle(){
    points.reserve(other.points.size());
    points = other.points;
    center = other.center;
    area = other.area;
    type = other.type;
}

Rectangle::Rectangle(Rectangle&& other) noexcept : Rectangle(){
    points.reserve(other.points.size());
    points = other.points;
    center = other.center;
    area = other.area;
    type = other.type;
    delete& other;
}