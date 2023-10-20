// (c) anton perceptronica, 2023

#include "Segment.hpp"

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