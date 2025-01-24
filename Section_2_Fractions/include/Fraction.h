#pragma once
#include <string>

class Fraction {
public:
    Fraction(int a, int b);

    Fraction reciprocal();

    Fraction multiply(int a);

    double toDouble();

    std::string toString();

private:
    void simplify();

    int getGCD();

    int mA;
    int mB;
};
