// (c) anton perceptronica, 2023

#include "Segment.hpp"

using namespace std;

Segment::Segment(Point r1_, Point r2_) {
    if (r1_ == r2_) {
        throw invalid_argument("Start and end of the segment \
                                are the same!\n");
    }

    r1 = r1_;
    r2 = r2_;

    Point dr = r2 - r1; // откладываем такой же вектор от начала координат
                        // для вычисления произведений
}

bool Segment::operator||(const Segment & rhs) const {
    return (getDR() ^ rhs.getDR()) == 0;
}

double Segment::length() const {
    return dr.length();
}

Point Segment::getR1() const{
    return r1;
}

Point Segment::getR2() const{
    return r2;
}

Point Segment::getDR() const{
    return dr;
}

double operator*(const Segment & s1, const Segment & s2) {
    return s1.getDR() * s2.getDR();
}
double operator^(const Segment & s1, const Segment & s2) {
    return s1.getDR() ^ s2.getDR();
}
