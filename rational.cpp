#include "rational.h"


int gcd(int a, int b)
{
    if(a < 0)
        a = -(a);
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

Rational::Rational(int numerator, int denominator)
{
    try
    {
        if(denominator == 0)
            throw 0;

        if(denominator < 0)
        {
            denominator = -(denominator);
            numerator = -(numerator);
        }
        numerator_ = numerator;
        denominator_ = denominator;
        this->reduce();

    }
    catch(int)
    {
        std::cerr << "Denominator cannot be zero! Default constructor will be called.";
        numerator_ = 0;
        denominator_ = 1;
    }
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

Rational& Rational::set_denominator(int denominator)
{
    int multiplier = denominator / denominator_;
    numerator_ *= multiplier;
    denominator_ *= multiplier;
    return *this;
}


Rational& Rational::add(Rational &rational)
{
    if(denominator_ != rational.denominator_)
    {
        int lcm_value = lcm(denominator_, rational.denominator_);
        set_denominator(lcm_value);
        rational.set_denominator(lcm_value);
        this->add(rational);
    }
    else
    {
        numerator_ += rational.numerator_;
    }
    this->reduce();
    return *this;

}


Rational& Rational::sub(Rational &rational)
{
   Rational temp(-(rational.numerator_), rational.denominator_);
   this->add(temp);
   return *this;
}

Rational& Rational::mul(Rational &rational)
{
    numerator_ *= rational.numerator_;
    denominator_ *= rational.denominator_;
    reduce();
    return *this;
}

Rational& Rational::div(Rational &rational)
{
    numerator_ *= rational.denominator_;
    denominator_ *= rational.numerator_;
    reduce();
    return *this;
}

Rational& Rational::neg()
{
    numerator_ = -(numerator_);
    return *this;
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

Rational& Rational::reduce()
{
    int gcd_ = gcd(numerator_, denominator_);
    numerator_ /= gcd_;
    denominator_ /= gcd_;
    return *this;
}

std::ostream& operator <<(std::ostream& os, const Rational& rational)
{
    os << rational.get_numerator() << '/' << rational.get_denominator();
    return os;
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

