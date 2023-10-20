// (c) anton perceptronica, 2023

#include "GeometryAlgo.hpp"
#include "Constants.hpp"
#include <algorithm>

vector<Point> Graham(vector<Point> points) {
    Point r0 = points[0];
    for (Point r : points) {
        if (r.getX() < r0.getX() || 
            ((abs(r.getX() - r0.getX()) < EPS) 
            && r.getY() < r0.getY())) {
                r0 = r;
        }
    }
    sort(points.begin(), points.end(), [&](Point a, Point b){
        return ((a - r0) ^ (b - r0)) > 0;
    });

    vector<Point> hull;
    for (Point p : points) {
        // удаляем последнюю точку со стека пока она образует невыпуклость
        while (hull.size() >= 2) {
            Point new_vector = p - hull.back();
            Point last_vector = hull.back() - hull[hull.size() - 2];
            // если два последних вектора заворачивают влево, удаляем последнюю точку
            if ((new_vector ^ last_vector) > 0)
                hull.pop_back();
            else
                break;
        }
        hull.push_back(p);
    }
    return hull;
}