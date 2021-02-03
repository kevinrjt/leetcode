#include <algorithm>

using namespace std;

#define SOLUTION_3

#ifdef SOLUTION_1
int arrangeCoins(int n)
{
    int k = 0;
    int m = 0;
    while (m <= n)
    {
        ++k;
        m += k;
    }

    return k - 1;
}
#endif

#ifdef SOLUTION_2
int arrangeCoins(int n)
{
    return (int)floor((sqrt(1 + 8.0 * n) - 1) / 2);
}
#endif

#ifdef SOLUTION_3
int arrangeCoins(int n)
{
    long long low = 0;
    long long high = n + 1L;
    while (low < high)
    {
        long long mid = low + (high - low) / 2;
        if (mid * (mid + 1) / 2 <= n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low - 1;
}
#endif

int main()
{
    return 0;
}