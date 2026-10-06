#include <iostream>

using namespace std;

// 1. operator overloading is the way in which we can teach C++ how to perform
// operations on our own custom defined data types - for eg. classes

class Fraction
{
public:
    int numerator;
    int denominator;

    // constructor
    Fraction(int n, int d) : numerator(n), denominator(d) {}

    // our first operator overloading
    // return-type Fraction
    // operator+ -> function associated with the '+' operator
    //(const Fraction &other) -> const is basically used to show that we promise we won't make
    // any change to the 'other' variable and other is passed by reference as a parameter
    // we can use 'this' keyword to denote the current Fraction instance we are working with

    // a+b conceptually becomes a.operator+(b)
    // where a is the current object and b is the other

    Fraction operator+(const Fraction &other) const
    {
        return Fraction(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    // member and non-member functions
    // let's say we want to perform vector multiplication with a scalar
    // changing the order while we are performing such operation can cause
    // problems

    void print() const
    {
        cout << numerator << "/" << denominator << "\n";
    }
};

int main()
{
    Fraction a(1, 2);
    Fraction b(3, 4);

    Fraction c = a + b;
    c.print();
}