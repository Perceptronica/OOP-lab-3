// (c) anton perceptronica, 2023

#include "Point.hpp"

Point::Point(Point&& other) noexcept {
    x = other.x;
    y = other.y;
    other.x = 0;
    other.y = 0;
}

Point Point::operator=(const Point& other) {
    if (this == &other) return *this;
    x = other.x;
    y = other.y;
    return *this;
}

Point Point::operator=(Point&& other) noexcept {
    if (this == &other) return *this;
    x = other.x;
    y = other.y;
    other.x = 0;
    other.y = 0;
    return *this;
}

double Point::length() const {
    return sqrt(getX() * getX() + getY() * getY());
}

Point Point::operator+(const Point& other) const {
    return {x + other.x, y + other.y};
}

Point Point::operator-(const Point& other) const {
    return {x - other.x, y - other.y};
}