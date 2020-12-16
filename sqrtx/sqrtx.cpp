#define SOLUTION_1

#ifdef SOLUTION_1
int mySqrt(int x)
{
    if (x == 0)
    {
        return 0;
    }

    int low = 1;
    int high = x;
    while (high - low > 1)
    {
        int mid = low + (high - low) / 2;
        if (mid > x / mid)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    };

    return low;
}
#endif

#ifdef SOLUTION_2
// https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
int mySqrt(int x)
{
    long long s = x;
    while (s * s > x)
    {
        s = (s + x / s) / 2;
    }

    return s;
}
#endif

int main()
{
    return 0;
}