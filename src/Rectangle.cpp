// (c) anton perceptronica, 2023

#include "Rectangle.hpp"

Rectangle::Rectangle(vector<Point> & _points) : Rectangle() {
    points = _points;
    center = calculateCenter(points);
    area = calculateArea(points);
}

Rectangle::Rectangle(vector<Point> && _points) : Rectangle() {
    points = _points;
    center = calculateCenter(points);
    area = calculateArea(points);
}

Rectangle::Rectangle(const Rectangle & other) : Rectangle() {
    points = other.getPoints();
    center = other.getCenter();
    area = other.getArea();
}

Rectangle::Rectangle(Rectangle && other) noexcept : Rectangle() {
    points = other.getPoints();
    center = other.getCenter();
    area = other.getArea();
    delete &other;
}