// (c) anton perceptronica, 2023

#include "Validators.hpp"

bool PointsCoincide(const vector<Point>& _points) {
    for (int i {1}; i < _points.size(); ++i) {
        if (_points[i] == _points[i - 1]) return true;
    }
    return false;
}

bool isSquare(const vector<Point>& _points) {
    vector<Segment> s;
    int n = _points.size();
    for (int i {0}; i < n; ++i) {
        s.push_back(Segment(_points[i], 
                              _points[(i + 1) % n]));
    } 
    return isRectangle(_points) &&
           s[0].length() == s[1].length() &&
           s[1].length() == s[2].length();
}

bool isRectangle(const vector<Point>& _points) {
    vector<Segment> s;
    int n = _points.size();
    for (int i {0}; i < n; ++i) {
        s.push_back(Segment(_points[i], 
                              _points[(i + 1) % n]));
    }
    return s[0] % s[1] && s[1] % s[2] &&
           s[2] % s[3] && s[3] % s[0];
}

int getOrientation(const Point& p1, const Point& p2, const Point& p3) {
    double orientation = (p2.getY() - p1.getY()) * 
                         (p3.getX() - p2.getX()) - 
                         (p3.getY() - p2.getY()) * 
                         (p2.getX() - p1.getX());
    
    if (orientation > 0) {
        return 1; // Против часовой стрелки
    } else if (orientation < 0) {
        return -1; // По часовой стрелке
    } else {
        return 0; // Вырожденный случай
    }
}

bool isConvex(const vector<Point>& _points) {
    if (_points.size() < 3) {
        return false;
    }

    int numPoints = _points.size();
    int orientation = 0; // Ориентация фигуры: 0 - не определена, 1 - против часовой стрелки, -1 - по часовой стрелке

    for (int i = 0; i < numPoints; i++) {
        int currentOrientation = getOrientation(_points[i], _points[(i + 1) % numPoints], _points[(i + 2) % numPoints]);
        if (currentOrientation == 0) {
            continue; // Пропускаем вырожденные случаи
        }
        if (orientation == 0) {
            orientation = currentOrientation;
        }
        if (orientation != currentOrientation) {
            return false;
        }
    }
    return true;
}

void Validator::validate(const vector<Point>& _points) {
    if (_points.size() != 4) {
        throw logic_error("Task requires a four-point figure!");
    } else if (!(isConvex(_points))) {
        throw logic_error("The figure is not convex!");
    } else if (PointsCoincide(_points)) {
        throw logic_error("Points coincide => not a 4-point figure!");
    }
}

void RectangleValidator::validate(const vector<Point>& _points) {
    if(!(isRectangle(_points))) {
        throw logic_error("The figure is convex but \
                           not a rectangle.");
    }
}

void SquareValidator::validate(const vector<Point>& _points) {
    if (!(isRectangle(_points))) {
        throw logic_error("The figure is convex but \
                           not a rectangle.");
    } else {

    }
}

void TrapezoidValidator::validate(const vector<Point>& _points) {
    //...
}