// (c) anton perceptronica, 2023

#pragma once

#include <iostream>
#include <cmath>

using namespace std;

const long double EPS = 1e-10;

class Point {
private:
    double x;
    double y;

public:
    Point(): x(0.0), y(0.0) {};
    Point(double x_, double y_): x(x_), y(y_) {};
    
    Point(const Point& other): x(other.x), y(other.y) {};
    Point(Point&& other) noexcept; 
    Point operator=(const Point& other);
    Point operator=(Point&& other) noexcept;

    ~Point() = default;

    double getX() const { return x; }
    double getY() const { return y; }
    double length() const; // так как точка ≃ радиус-вектор

    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;

    bool operator==(const Point& other) const;

    void setX(double x_) { this->x = x_; }
    void setY(double y_) { this->y = y_; }
};

double operator*(const Point& r1, const Point& r2);
double operator^(const Point& r1, const Point& r2);

istream& operator>>(istream& in, Point& r);
ostream& operator<<(ostream& out, const Point& r);
/*
- конструктор по умолчанию
- конструктор с параметрами
- конструктор копирования (1)
- конструктор перемещения (2)
- оператор присваивания копированием (3)
- оператор присваивания перемещением (4)
- деструктор (5)
*/