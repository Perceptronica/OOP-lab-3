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

bool Point::operator==(const Point& other) const {
    return abs(x - other.x) < EPS && 
           abs(y - other.y) < EPS;
}

istream& operator>>(istream& in, Point& r) {
    in >> r.x >> r.y;
    return in;
}

ostream& operator<<(ostream& out, const Point& r) {
    out << "(" << r.getX() << ", " << r.getY() << ")" << endl;
    return out;
}

double operator*(const Point& r1, const Point& r2) {
    return r1.getX() * r2.getX() + r1.getY() * r2.getY();
}

double operator^(const Point& r1, const Point& r2) {
    return r1.getX() * r2.getY() - r1.getY() * r2.getX();
}