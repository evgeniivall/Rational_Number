#include <iostream>
#include "rational.h"

using namespace std;

int main()
{
    Rational d1(3, 0);
    cout << endl << d1;
    Rational d2(2, 7);
    cout << endl << d2;
    std::cout << endl << (d1 - d2);




    return 0;
}
