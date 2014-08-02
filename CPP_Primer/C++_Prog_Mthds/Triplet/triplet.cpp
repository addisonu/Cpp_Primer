//07/15/14
//
//Project 5 : Part A
//triplet.cpp
//Implementation file for triplet class which provides a "triple" object of three integer type and applicable operations

#include <iostream>
#include "triplet.h"

Triplet::Triplet(int value)
{
    data[0] = value;
    data[1] = value;
    data[2] = value;
}

Triplet::Triplet(int val1, int val2, int val3)
{
    data[0] = val1;
    data[1] = val2;
    data[2] = val3;
}

const Triplet Triplet::operator+(const Triplet &operand) const
{
    const Triplet sum((data[0] + operand.data[0]), (data[1] + operand.data[1]), (data[2] + operand.data[2]));
    return sum;
}

const Triplet Triplet::operator-(const Triplet &operand) const
{
    const Triplet diff((data[0] - operand.data[0]), (data[1] - operand.data[1]), (data[2] - operand.data[2]));
    return diff;
}

Triplet Triplet::operator++(int num)
{
    data[0] += 1;
    data[1] += 1;
    data[2] += 1;
    return *this;
}

Triplet Triplet::operator++()
{
    data[0] += 1;
    data[1] += 1;
    data[2] += 1;
    return *this;
}

bool Triplet::operator==(const Triplet &operand) const
{
    return (data[0] == operand.data[0]) && (data[1] == operand.data[1]) && (data[2] == operand.data[2]);
}

bool Triplet::operator>(const Triplet &operand) const
{
    return (data[0] > operand.data[0]) && (data[1] > operand.data[1]) && (data[2] > operand.data[2]);
}

const int& Triplet::operator[](int index) const
{
    return data[index];
}

std::istream &operator>>(std::istream &in, Triplet &robject)
{
    in >> robject.data[0] >> robject.data[1] >> robject.data[2];
    return in;
}

std::ostream &operator<<(std::ostream &out, const Triplet &robject)
{
    out << robject.data[0] << ", " << robject.data[1] << ", " << robject.data[2];
    return out;
}

Triplet operator*(const Triplet &operand, const Triplet &operand2)
{
    Triplet prod(operand[0]*operand2[0], operand[1]*operand2[1], operand[2]*operand2[2]);
    return prod;
}
