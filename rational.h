#ifndef RATIONAL_H
#define RATIONAL_H

int gcd(int a, int b);
int lcm(int m, int n);
struct Rational
{
    Rational(int numerator = 0, int denominator = 1):numerator_(numerator), denominator_(denominator){}
    Rational(const Rational& );

    Rational& operator =(const Rational& );

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    Rational& operator+=(Rational rational);
    Rational& operator-=(Rational rational);
    Rational& operator*=(Rational rational);
    Rational& operator/=(Rational rational);

    Rational denum(int);


    Rational operator-() const;
    Rational operator+() const;

    double to_double()const
    {
        return((double)numerator_ / denominator_);
    }
    void neg();
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


private:
    int numerator_;
    int denominator_;
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
