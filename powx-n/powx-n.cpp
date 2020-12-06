#include <iostream>

using namespace std;

double myPow(double x, int n)
{
    if (n < 0)
    {
        return 1 / (x * myPow(x, -(n + 1)));
    }

    double pow = 1;
    while (n)
    {
        if (n & 1)
        {
            pow *= x;
        }

        x *= x;
        n >>= 1;
    }

    return pow;
}

int main()
{
    cout << myPow(2, 10) << endl;
    cout << myPow(2, 11) << endl;
    cout << myPow(2, 12) << endl;
    cout << myPow(2, 13) << endl;
    return 0;
}