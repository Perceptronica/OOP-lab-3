// (c) anton perceptronica, 2023

#include "Figure.hpp"
#include <iostream>
using namespace std;

int main() {
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
}