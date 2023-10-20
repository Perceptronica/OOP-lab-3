// (c) anton perceptronica, 2023

#include "Figure.hpp"

void Figure::normalizePoints() {
    // алгоритм Грехема для вычисления выпуклой 
    // оболочки множества точек => проверка выпуклости
    // фигуры
    Point r0 = points[0];
    for (Point r : points) {
        if (r.getX() < r0.getX() || 
            ((abs(r.getX() - r0.getX()) < EPS) 
            && r.getY() < r0.getY())) {
                r0 = r;
        }
    }
    sort(points.begin(), points.end(), [&](Point a, Point b){
        return ((a - r0) ^ (b - r0)) > EPS;
    });

    vector<Point> hull;
    for (Point p : points) {
        // удаляем последнюю точку со стека, 
        // пока она образует невыпуклость
        while (hull.size() >= 2) {
            Point new_vector = p - hull.back();
            Point last_vector = hull.back() - hull[hull.size() - 2];
            // если два последних вектора заворачивают 
            // влево, удаляем последнюю точку
            if ((new_vector ^ last_vector) > EPS)
                hull.pop_back();
            else
                break;
        }
        hull.push_back(p);
    }
    points = hull;
}

void Figure::calculateArea() {
    int n = points.size();
    if (n >= 3) {
        double s = 0;
        for (int i = 0; i < n; ++i) {
            s += points[i] ^ points[(i + 1) % n];
        } 
        area = abs(s) / 2;
    } else {
        area = 0.0;
    }
}

void Figure::calculateCenter() {
    int n = points.size();
    if (n >= 3) {
        double sumX {0.0};
        double sumY {0.0};
        for (Point p: points) {
            sumX += p.getX();
            sumY += p.getY();
        }
        center = {sumX / n, sumY / n};
    } else {
        center = {-1e8, -1e8};
    }
}

Figure::Figure(vector<Point>& _points) {
    points.reserve(_points.size());
    points = _points;
    normalizePoints();
    calculateArea();
    calculateCenter();
}

Figure::Figure(const Figure& other) {
    points.reserve(other.points.size());
    points = other.points;
}

Figure::Figure(Figure&& other) noexcept {
    points.reserve(other.points.size());
    points = other.points;
    other.points.clear();
}

Figure Figure::operator=(const Figure& other) {
    if (this == &other) return *this;
    points.reserve(other.points.size());
    points = other.points;
    return *this;
}
Figure Figure::operator=(Figure&& other) noexcept {
    if (this == &other) return *this;
    points.reserve(other.points.size());
    points = other.points;
    other.points.clear();
    return *this;
}

ostream& Figure::operator<<(ostream& out) {
    out << "Points: ";
    for (Point &p: points) {
        out << p << "; ";
    }
    out << endl;
    out << "Center: " << getCenter() << endl;
    out << "Area: " << getArea() << endl;
    return out;
}