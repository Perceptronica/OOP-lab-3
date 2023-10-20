// (c) anton perceptronica, 2023

#include "Point.hpp"
#include "Constants.hpp"

using namespace std;

Point::Point(const Point & other) : x(other.x), y(other.y) {}

Point::Point(Point && other) noexcept {
    x = other.x;
    y = other.y;

    other.x = 0;
    other.y = 0;
}

double Point::getX() const { return x; }

double Point::getY() const { return y; }

double Point::length() const {
    return sqrt(getX() * getX() + getY() * getY());
}

Point Point::operator+(const Point & rhs) const {
    return {x + rhs.x, y + rhs.y};
}

Point Point::operator-(const Point & rhs) const {
    return {x - rhs.x, y - rhs.y};
}

Point Point::operator=(const Point & rhs) {
    x = rhs.x;
    y = rhs.y;
    return *this;
}

Point Point::operator=(Point && rhs) {
    x = rhs.x;
    y = rhs.y;

    rhs.x = 0;
    rhs.y = 0;

    return *this;
}

bool Point::operator==(const Point & rhs) const {
    return abs(x - rhs.x) < EPS && abs(y - rhs.y) < EPS; 
}

double operator*(const Point & r1, const Point & r2) {
    return r1.getX() * r2.getX() + r1.getY() * r2.getY();
}

double operator^(const Point & r1, const Point & r2) {
    return r1.getX() * r2.getY() - r1.getY() * r2.getX();
}

ostream & operator<<(ostream & out, const Point & r) {
    out << "(" << r.getX() << ", " << r.getY() << ")";
    return out;
}
istream & operator>>(istream & in, Point & r) {
    in >> r.x >> r.y;
    return in;
}