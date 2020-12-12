#include <iostream>

using namespace std;

bool isPalindrome(int x)
{
    if (x < 0 || (x != 0 && x % 10 == 0))
    {
        return false;
    }

    int r = 0;
    while (r < x)
    {
        r = 10 * r + x % 10;
        x /= 10;
    }

    return r == x || r / 10 == x;
}

int main()
{
    return 0;
}