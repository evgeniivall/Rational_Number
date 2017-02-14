#include <iostream>
#include "rational.h"

using namespace std;

int main()
{
    Rational d1(5, 6);
    Rational d2(2, 7);

    std::cout << (d1 < d2);




    return 0;
}
