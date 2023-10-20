// (c) anton perceptronica, 2023

#pragma once

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

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
};

/*
- конструктор по умолчанию
- конструктор с параметрами
- конструктор копирования (1)
- конструктор перемещения (2)
- оператор присваивания копированием (3)
- оператор присваивания перемещением (4)
- деструктор (5)
*/