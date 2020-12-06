#include <iostream>
#include <utility>

using namespace std;

#define SOLUTION_1

#ifdef SOLUTION_1
int climbStairs(int n)
{
    int prevResult = 1;
    int result = 1;
    for (int i = 2; i <= n; ++i)
    {
        int nextResult = prevResult + result;
        prevResult = result;
        result = nextResult;
    }

    return result;
}
#endif

#ifdef SOLUTION_2
typedef pair<pair<int, int>, pair<int, int>> Matrix;

int dot(const pair<int, int> &x, const pair<int, int> &y)
{
    return x.first * y.first + x.second * y.second;
}

Matrix multiply(const Matrix &x, const Matrix &y)
{
    return Matrix{{dot(x.first, y.first), dot(x.first, y.second)}, {dot(x.second, y.first), dot(x.second, y.second)}};
}

Matrix matrixPow(Matrix &x, int n)
{
    Matrix pow{{1, 0}, {0, 1}};
    while (n)
    {
        if (n & 1)
        {
            pow = multiply(pow, x);
        }

        if (n > 1)
        {
            x = multiply(x, x);
        }

        n >>= 1;
    }

    return pow;
}

int climbStairs(int n)
{
    Matrix x{{1, 1}, {1, 0}};
    Matrix pow = matrixPow(x, n);
    return pow.first.first;
}
#endif

int main()
{
    cout << climbStairs(1) << endl;
    cout << climbStairs(2) << endl;
    cout << climbStairs(3) << endl;
    cout << climbStairs(4) << endl;
    cout << climbStairs(5) << endl;
    return 0;
}