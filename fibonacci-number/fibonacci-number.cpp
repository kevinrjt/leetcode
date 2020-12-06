#include <utility>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
int fib(int N)
{
    int prevFn = 1;
    int fn = 0;
    for (int i = 1; i <= N; ++i)
    {
        int nextFn = prevFn + fn;
        prevFn = fn;
        fn = nextFn;
    }

    return fn;
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

        x = multiply(x, x);
        n >>= 1;
    }

    return pow;
}

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }

    Matrix x{{1, 1}, {1, 0}};
    Matrix pow = matrixPow(x, n - 1);
    return pow.first.first;
}
#endif

int main()
{
    return 0;
}