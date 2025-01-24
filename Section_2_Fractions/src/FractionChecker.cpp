#include "Fraction.h"
#include <iostream>

bool approx(double a, double b, double epsilon)
{
    return std::abs(a - b) <= epsilon;
}

bool checkDoubleConversion()
{
    // We use the approx feature here because floating point arithmetic is not exact
    // epsilon is the amount of error that we allow 
    bool okay = approx(Fraction(1, 2).toDouble(), 0.5, 1e-10);

    okay &= approx(Fraction(2, 3).toDouble(), 2.0/3.0, 1e-10);

    okay &= approx(Fraction(0, 15).toDouble(), 0, 1e-10);

    okay &= approx(Fraction(2, 4).toDouble(), 0.5, 1e-10);

    return okay;
}

bool checkStringConversion()
{
    bool okay = Fraction(1, 2).toString() == "1/2";

    okay &= Fraction(2, 3).toString() == "2/3";

    okay &= Fraction(7, 9).toString() == "7/9";

    okay &= Fraction(0, 5).toString() == "0";

    okay &= Fraction(0, 12).toString() == "0";

    okay &= Fraction(2, 0).toString() == "infinity";
    
    return okay;
}

bool checkMultiply()
{
    bool okay = Fraction(1, 2).multiply(2).toString() == "1";
    okay &= Fraction(1, 2).multiply(3).toString() == "3/2";
    
    okay &= Fraction(2, 3).multiply(6).toString() == "4";

    okay &= Fraction(7, 9).multiply(3).toString() == "7/3";
    okay &= Fraction(7, 9).multiply(5).toString() == "35/9";
    
    okay &= Fraction(0, 5).multiply(2).toString() == "0";
 
    okay &= Fraction(2, 0).multiply(2).toString() == "infinity";

    return okay;
}

bool checkSimplify()
{
    bool okay = Fraction(1, 2).toString() == "1/2";
    
    okay &= Fraction(10, 20).toString() == "1/2";

    okay &= Fraction(9, 3).toString() == "3";

    okay &= Fraction(8, 64).toString() == "1/8";
    
    return okay;
}

bool checkReciprocal()
{
    bool okay = Fraction(1, 2).reciprocal().toString() == "2";

    okay &= Fraction(2, 3).reciprocal().toString() == "3/2";

    okay &= Fraction(7, 9).reciprocal().toString() == "9/7";
    
    okay &= Fraction(0, 5).reciprocal().toString() == "infinity";
 
    okay &= Fraction(2, 0).reciprocal().toString() == "2";

    return okay;
}

int main()
{
    std::cout << "Check double conversion." << std::endl;
    std::cout << (checkDoubleConversion() ? "Double conversion okay." : "Double conversion incorrect.") << std::endl;

    std::cout << "Check string conversion." << std::endl;
    std::cout << (checkStringConversion() ? "String conversion okay." : "String conversion incorrect.") << std::endl;

    std::cout << "Check multiply." << std::endl;
    std::cout << (checkMultiply() ? "Multiply okay." : "Multiply incorrect.") << std::endl;

    std::cout << "Check simplify." << std::endl;
    std::cout << (checkMultiply() ? "Simplify okay." : "Simplify incorrect.") << std::endl;

    std::cout << "Check reciprocal." << std::endl;
    std::cout << (checkMultiply() ? "Reciprocal okay." : "Reciprocal incorrect.") << std::endl;
    
    return 0;
}