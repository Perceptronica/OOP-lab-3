// (c) anton perceptronica, 2023

#include "Point.hpp"

using namespace std;

Point::Point(const Point & other) : x(other.x), y(other.y) {}

Point::Point(Point && other) {
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

// TODO: rewrite with EPS!!!
bool Point::operator==(const Point & rhs) const {
    return x == rhs.x && y == rhs.y; 
}

double operator*(const Point & r1, const Point & r2) {
    return r1.getX() * r2.getX() + r1.getY() * r2.getY();
}

double operator^(const Point & r1, const Point & r2) {
    return r1.getX() * r2.getY() - r1.getY() * r2.getX();
}