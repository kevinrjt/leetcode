#include <iostream>

using namespace std;

int reverse(int x)
{
    int r = 0;
    const int threshold = INT_MAX / 10;
    while (x)
    {
        if (r > threshold || r < -threshold)
        {
            return 0;
        }

        r = 10 * r + x % 10;
        x /= 10;
    }

    return r;
}

int main()
{
    cout << reverse(123) << endl;
    cout << reverse(-123) << endl;
    cout << reverse(120) << endl;
    cout << reverse(0) << endl;
    cout << INT_MAX << " " << reverse(INT_MAX) << endl;
    cout << INT_MIN << " " << reverse(INT_MIN) << endl;
    return 0;
}