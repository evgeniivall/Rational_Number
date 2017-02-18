#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
int gcd(int a, int b);
int lcm(int m, int n);


struct Rational
{
    Rational():numerator_(0), denominator_(1){}
    Rational(int numerator, int denominator);
    Rational(const Rational& );

    Rational& operator =(const Rational& );

    Rational& add(Rational &rational);
    Rational& sub(Rational &rational);
    Rational& mul(Rational &rational);
    Rational& div(Rational &rational);

    Rational& operator+=(Rational rational);
    Rational& operator-=(Rational rational);
    Rational& operator*=(Rational rational);
    Rational& operator/=(Rational rational);

    Rational& set_denominator(int denominator);


    Rational operator-() const;
    Rational operator+() const;

    double to_double()const
    {
        return((double)numerator_ / denominator_);
    }
    Rational& neg();
    operator double()const
    {
        return this->to_double();
    }

    int get_numerator()const
    {
        return numerator_;
    }

    int get_denominator()const
    {
        return denominator_;
    }
    Rational& reduce();
    friend std::ostream& operator <<(std::ostream& os, const Rational& rational);

private:
    int numerator_;
    unsigned denominator_;
};

Rational operator+(Rational lhs, Rational rhs);
Rational operator-(Rational lhs, Rational rhs);
Rational operator*(Rational lhs, Rational rhs);
Rational operator/(Rational lhs, Rational rhs);

bool operator==(const Rational &lhs, const Rational &rhs);
bool operator!=(const Rational &lhs, const Rational &rhs);
bool operator< (const Rational &lhs, const Rational &rhs);
bool operator> (const Rational &lhs, const Rational &rhs);
bool operator<=(const Rational &lhs, const Rational &rhs);
bool operator>=(const Rational &lhs, const Rational &rhs);



#endif // RATIONAL_H
