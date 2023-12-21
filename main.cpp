// (c) anton perceptronica, 2023

#include "Figure.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Trapezoid.hpp"
#include <iostream>

using namespace std;

int main() {
    int command;
    cout << "enter the command: ";
    cin >> command;
    if (command == 0) {
        int n;
        vector<Point> r;
        cout << "Enter the amount of coordinates:" << endl;
        cin >> n;
        Point curr;
        cout << "Enter the coordinates: x y" << endl; 
        for (int i = 0; i < n; ++i) {
            cin >> curr;
            r.push_back(curr);
        }
        Figure f(r);
        cout << f;
    } else if (command == 1) {
        vector <Point> rect_points = {Point(0, 0), Point(1, 0), Point(1, 5), Point(0, 5)};
        vector <Point> sq_points = {Point(0, 0), Point(1, 1), Point(1, 0), Point(0, 1)};
        vector <Point> tp_points = {Point(-1, 3), Point(3, 3), Point(-3, 1), Point(4, 1)};

        Rectangle rect(rect_points);
        Square sq(sq_points);
        Trapezoid tp(tp_points);
        cout << rect;
        cout << sq;
        cout << tp;
    }    
}