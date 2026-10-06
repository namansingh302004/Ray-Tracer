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

    // compund operators like '+='
    // we are not using const here - basically we don't promise we won't change the current instance
    // and yeah that is what we want to do - update the current object

    Fraction &operator+=(const Fraction &other)
    {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator = denominator * other.denominator;

        return *this;
    }

    // member and non-member functions
    // let's say we want to perform vector multiplication with a scalar
    // changing the order while we are performing such operation can cause
    // problems

    Fraction operator*(int scalar) const
    {
        return Fraction(
            this->numerator * scalar,
            denominator);
    }

    // unary operator
    Fraction operator-() const
    {
        return Fraction(
            -numerator, denominator);
    }

    void print() const
    {
        cout << numerator << "/" << denominator << "\n";
    }
};

// non-member operator
Fraction operator*(int scalar, const Fraction &fraction)
{
    return Fraction(
        fraction.numerator * scalar,
        fraction.denominator);
}

int main()
{
    Fraction a(1, 2);
    Fraction b(3, 4);

    Fraction c = a + b;
    c.print();

    Fraction d = a * 3;
    d.print();

    Fraction e = 3 * a;
    e.print();
}