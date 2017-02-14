#include "rational.h"


int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
        return gcd(b, a % b);
}

int lcm(int m, int n)
{
    return (m / gcd(m, n) * n);
}


Rational::Rational(const Rational& rational)
{
    numerator_ = rational.numerator_;
    denominator_ = rational.denominator_;
}

Rational& Rational::operator =(const Rational& rational)
{
    numerator_ = rational.numerator_;
    denominator_ = rational.denominator_;
    return *this;
}

Rational Rational::denum(int lcm)
{
    int multiplier = lcm / denominator_;
    Rational temp(numerator_ * multiplier, denominator_ * multiplier);
    return temp;
}


void Rational::add(Rational rational)
{
    if(denominator_ != rational.denominator_)
    {
        int lcm_value = lcm(denominator_, rational.denominator_);
        *this = this->denum(lcm_value);
        rational = rational.denum(lcm_value);
        this->add(rational);
    }
    else
    {
        numerator_ += rational.numerator_;
    }

}


void Rational::sub(Rational rational)
{
    if(denominator_ != rational.denominator_)
    {
        int lcm_value = lcm(denominator_, rational.denominator_);
        *this = this->denum(lcm_value);
        rational = rational.denum(lcm_value);
        this->sub(rational);
    }
    else
    {
        numerator_ -= rational.numerator_;
    }
}

void Rational::mul(Rational rational)
{
    numerator_ *= rational.numerator_;
    denominator_ *= rational.denominator_;
}

void Rational::div(Rational rational)
{
    numerator_ *= rational.denominator_;
    denominator_ *= rational.numerator_;
}

void Rational::neg()
{
    numerator_ = -(numerator_);
}

Rational& Rational::operator+=(Rational rational)
{
    this->add(rational);
    return *this;
}

Rational& Rational::operator-=(Rational rational)
{
    this->sub(rational);
    return *this;
}

Rational& Rational::operator*=(Rational rational)
{
    this->mul(rational);
    return *this;
}

Rational& Rational::operator/=(Rational rational)
{
    this->div(rational);
    return *this;
}

Rational Rational::operator-() const
{
    Rational number(this->numerator_, this->denominator_);
    number.neg();
    return number;
}

Rational Rational::operator+() const
{
    Rational number(this->numerator_, this->denominator_);
    return number;
}

Rational operator+(Rational lhs, Rational rhs)
{
    return lhs += rhs;
}

Rational operator-(Rational lhs, Rational rhs)
{
    return lhs -= rhs;
}

Rational operator*(Rational lhs, Rational rhs)
{
    return lhs *= rhs;
}

Rational operator/(Rational lhs, Rational rhs)
{
    return lhs /= rhs;
}



bool operator==(const Rational &lhs, const Rational &rhs)
{

    return ((lhs.get_denominator()*rhs.get_numerator()) ==
           (rhs.get_denominator()*lhs.get_numerator()));
}

bool operator!=(const Rational &lhs, const Rational &rhs)
{
    return !(lhs == rhs);
}

bool operator< (const Rational &lhs, const Rational &rhs)
{
    return ((lhs.get_denominator()*rhs.get_numerator()) <
           (rhs.get_denominator()*lhs.get_numerator()));
}

bool operator> (const Rational &lhs, const Rational &rhs)
{
    return rhs < lhs;
}

bool operator<=(const Rational &lhs, const Rational &rhs)
{
    return !(rhs < lhs);
}

bool operator>=(const Rational &lhs, const Rational &rhs)
{
    return !(lhs < rhs);
}

