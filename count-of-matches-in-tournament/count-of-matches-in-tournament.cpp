#include <iostream>
#include <vector>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
int numberOfMatches(int n)
{
    int num = 0;
    while (n > 1)
    {
        num += n / 2;
        n = (n / 2) + (n % 2);
    }

    return num;
}
#endif

#ifdef SOLUTION_2
int numberOfMatches(int n)
{
    return n - 1;
}
#endif

int main()
{
    return 0;
}