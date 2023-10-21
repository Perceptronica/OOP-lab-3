// (c) anton perceptronica, 2023

#include <gtest/gtest.h>
#include "Figure.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Trapezoid.hpp"
#include "Validators.hpp"

using namespace std;

vector<Point> vp = {Point(1,1), Point(3,1), Point(2,2), Point(2,0)};
vector<Point> vnc = {Point(2, 3), Point(1, -1), Point(2, -2), Point(-2, -2)};

// обработка исключений для фигуры в общем
class FigureExceptionHandling : public testing::TestWithParam<Figure> {};
class FigureConvexityCheck : public FigureExceptionHandling {};
class FigureNonConvexityCheck : public testing::TestWithParam<vector<Point>> {};

// выпуклость фигуры в общем:
TEST_P(FigureConvexityCheck, Convexity) {
    Figure f {GetParam()};
    bool convexity = isConvex(f.getPoints());
    ASSERT_TRUE(convexity);
}

INSTANTIATE_TEST_CASE_P(
    Convexity,
    FigureConvexityCheck,
    testing::Values(Figure(vp))
);

TEST_P(FigureNonConvexityCheck, NonConvexity) {
    vector <Point> v{GetParam()};
    bool convexity = isConvex(v);
    ASSERT_FALSE(convexity);
}

INSTANTIATE_TEST_CASE_P(
    NonConvexity,
    FigureNonConvexityCheck,
    testing::Values(vnc)
);