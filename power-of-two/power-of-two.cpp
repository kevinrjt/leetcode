#define SOLUTION_2

#ifdef SOLUTION_1
bool isPowerOfTwo(int n)
{
    long long p = 1;
    while (p < n)
    {
        p <<= 1;
    }

    return n == p;
}
#endif

#ifdef SOLUTION_2
bool isPowerOfTwo(int n)
{
    return n > 0 && !(n & (n - 1));
}
#endif

#ifdef SOLUTION_3
bool isPowerOfTwo(int n)
{
    return n > 0 && !(0x40000000 % n);
}
#endif

int main()
{
    return 0;
}