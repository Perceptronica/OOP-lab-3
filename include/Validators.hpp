// (c) anton perceptronica, 2023

#pragma once

#include "Point.hpp"


#ifndef VALIDATORS_HPP
#define VALIDATORS_HPP

class Validator {
public:
    virtual void validate(vector<Point> & _points) const;
};

class FigureValidator : public Validator {
public:
    virtual void validate(vector<Point> & _points) const override;
};

class RectangleValidator : public Validator {
public:
    virtual void validate(vector<Point> & _points) const override;
};

class SquareValidator : public Validator {
public:
    virtual void validate(vector<Point> & _points) const override;
};

class TrapezoidValidator : public Validator {
public:
    virtual void validate(vector<Point> & _points) const override;
};

#endif