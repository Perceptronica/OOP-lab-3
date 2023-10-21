// (c) anton percetronica, 2023

#include "Figure.hpp"

double angle(Point center, Point p) {
    double dx {p.getX() - center.getX()};
    double dy {p.getY() - center.getY()};
    return atan2(dy, dx);
}

void Figure::normalizePoints() {
    sort(points.begin(), points.end(), [&](const Point& p1, const Point& p2) {
        double angle1 {angle(center, p1)};
        double angle2 {angle(center, p2)};
        return angle1 < angle2;
    });
}

void Figure::calculateArea() {
    int n = points.size();
    if (n >= 3) {
        double s = 0;
        for (int i = 0; i < n; ++i) {
            s += (points[i] ^ points[(i + 1) % n]);
        } 
        area = s / 2;
        area = abs(area);
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
    calculateCenter();
    normalizePoints();
    Validator::validate(points);
    calculateArea();
    type = "undefined";
}

Figure::Figure(const Figure& other) {
    points.reserve(other.points.size());
    points = other.points;
    type = other.type;
    //validator = other.validator;
}

Figure::Figure(Figure&& other) noexcept {
    points.reserve(other.points.size());
    points = other.points;
    other.points.clear();
    type = other.type;
}

Figure Figure::operator=(const Figure& other) {
    if (this == &other) return *this;
    points.reserve(other.points.size());
    points = other.points;
    type = other.type;
    return *this;
}
Figure Figure::operator=(Figure&& other) noexcept {
    if (this == &other) return *this;
    points.reserve(other.points.size());
    points = other.points;
    other.points.clear();
    type = other.type;
    return *this;
}

ostream& operator<<(ostream& out, const Figure& f) {
    out << "Points: ";
    for (Point &p: f.getPoints()) {
        out << p << "; ";
    }
    out << endl << "Type: " << f.getType() << ";" << endl;
    out << "Center: " << f.getCenter() << ";" << endl;
    out << "Area: " << f.getArea() << ";" << endl;
    return out;
}