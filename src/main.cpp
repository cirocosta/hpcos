#include <iomanip>
#include <iostream>
#include <math.h>
#include <gmpxx.h>

using std::cout;
using std::endl;

double factorial(int n)
{
    if (!n)
        return 1;

    double res = n;

    while (--n)
        res *= n;

    return res;
}

int main() {
    long double result = 0.0;
    int x = 1;

    for (int i = 0; i < 10; i++) {
        if (i%2)
            result -= (pow(x, 2*i))/(factorial(2*i));
        else
            result += (pow(x, 2*i))/(factorial(2*i));
    }

    cout << std::setprecision(100) << result << endl;

    return 0;
}
