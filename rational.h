#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
int gcd(int a, int b);
int lcm(int m, int n);

class Exeption
{
public:
    virtual void Print_Warning_Message() = 0;
};
class NullDenominator : public Exeption
{
public:
    void Print_Warning_Message()
    {
        std::cerr  << "The value of denominator can`t be 0";
    }
};

struct Rational
{
    Rational(int numerator = 0, int denominator = 1);
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
