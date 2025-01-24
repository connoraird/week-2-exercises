#include "Fraction.h"

Fraction::Fraction(int a, int b)
{
    mA = a;
    mB = b;
    simplify();
}

Fraction Fraction::reciprocal()
{
    return Fraction(mB, mA);
}

Fraction Fraction::multiply(int a)
{
    return Fraction(mA * a, mB);

}

double Fraction::toDouble()
{
    if (mB == 0)
    {
        return (double)mA;
    }
    return (double)mA / (double)mB;
}

std::string Fraction::toString()
{
    std::string output = std::to_string(mA) + "/" + std::to_string(mB);
    
    if (mA == 0)
    {
        output = "0";
    }
    else if (mB == 0)
    {
        output = "infinity";
    }
    else if (mB == 1)
    {
        output = std::to_string(mA);
    }

    return output;
}

void Fraction::simplify()
{
    int gcd = getGCD();
    mA /= gcd;
    mB /= gcd;

    if (mA % mB == 0)
    {
        mA /= mB;
        mB = 1;
    }
}

int Fraction::getGCD() {
    // r_k0 = q_k *  r_k1 + r_k2, with r_k1 > r_k2 > 0
    // Gives the sequence {r_k0, r_k1, r_k2, ..., r_n}, where r_n = 0
    int r_k0 = mA;
    int r_k1 = mB;
    int r_k2 = r_k1;

    while (r_k2 != 0) {
        r_k2 = r_k0 % r_k1;
        r_k0 = r_k1;
        r_k1 = r_k2;
    }
    return r_k0;
}