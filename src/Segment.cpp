// (c) anton perceptronica, 2023

#include "Segment.hpp"

Segment::Segment(Point r1_, Point r2_) {
    if (r1_ == r2_) {
        throw invalid_argument("Segment cannot be null!");
    }
    
    r1 = r1_;
    r2 = r2_;
    dr = r2 - r1;
}

Segment::Segment(Segment&& other) noexcept {
    r1 = other.r1;
    r2 = other.r2;
    other.r1 = {0, 0};
    other.r2 = {0, 0};
}

Segment Segment::operator=(const Segment& other) {
    if (this == &other) return *this;
    r1 = other.r1;
    r2 = other.r2;
    return *this;
}
Segment Segment::operator=(Segment&& other) {
    if (this == &other) return *this;
    r1 = other.r1;
    r2 = other.r2;
    other.r1 = {0, 0};
    other.r2 = {0, 0};
    return *this;
}

bool Segment::operator||(const Segment& other) const {
    return (getDR() ^ other.getDR()) < EPS;
}

bool Segment::operator%(const Segment& other) const {
    return (getDR() * other.getDR()) < EPS; 
}

double operator*(const Segment& s1, const Segment& s2) {
    return s1.getDR() * s2.getDR();
}

double operator^(const Segment& s1, const Segment& s2) {
    return s1.getDR() ^ s2.getDR();
}