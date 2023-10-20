// (c) anton perceptronica, 2023

#include "Figure.hpp"
using namespace std;

int main() {
    vector<Point> r = {Point(0,0), Point(0,1), Point(1,0), Point(1,1)};
    Figure f(r);
    cout << f;
}