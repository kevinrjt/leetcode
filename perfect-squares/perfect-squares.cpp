#include <algorithm>
#include <vector>

using namespace std;

#define SOLUTION_1

#ifdef SOLUTION_1
int numSquares(int n)
{
    vector<int> table(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int minNum = i;
        for (int x = 1; x * x <= i; ++x)
        {
            minNum = min(minNum, table[i - x * x]);
        }

        table[i] = minNum + 1;
    }

    return table[n];
}
#endif

#ifdef SOLUTION_2
int numSquares(int n)
{
    int num = 0;
    vector<int> curr;
    curr.push_back(0);
    vector<char> visited(n + 1);
    visited[0] = 1;
    while (!curr.empty())
    {
        ++num;
        vector<int> next;
        for (int i : curr)
        {
            // sqrt is not O(1), but in practice it's fast enough
            int x = sqrt(n - i);
            if (x * x == n - i)
            {
                return num;
            }

            for (; x > 0; --x)
            {
                int m = i + x * x;
                if (!visited[m])
                {
                    next.push_back(m);
                    visited[m] = 1;
                }
            }
        }

        curr = move(next);
    }

    return num;
}
#endif

#ifdef SOLUTION_3
int numSquares(int n)
{
    vector<int> squares;
    for (int x = 1; x * x <= n; ++x)
    {
        squares.push_back(x * x);
    }

    int num = 0;
    vector<int> curr;
    curr.push_back(0);
    vector<char> visited(n + 1);
    visited[0] = 1;
    while (!curr.empty())
    {
        ++num;
        vector<int> next;
        for (int i : curr)
        {
            for (int s : squares)
            {
                int m = i + s;
                if (m == n)
                {
                    return num;
                }
                else if (m > n)
                {
                    break;
                }
                else if (!visited[m])
                {
                    next.push_back(m);
                    visited[m] = 1;
                }
            }
        }

        curr = move(next);
    }

    return num;
}
#endif

#ifdef SOLUTION_4
int numSquares(int n)
{
    // Cheating: reuse this table for all test cases
    static vector<int> table(1);
    while (table.size() <= n)
    {
        int m = table.size();
        int minNum = m;
        for (int x = 1; x * x <= m; ++x)
        {
            minNum = min(minNum, table[m - x * x]);
        }

        table.push_back(minNum + 1);
    }

    return table[n];
}
#endif

#ifdef SOLUTION_5
bool isSquare(int n)
{
    int root = sqrt(n);
    return root * root == n;
}

// https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem
int numSquares(int n)
{
    if (isSquare(n))
    {
        return 1;
    }

    while (n % 4 == 0)
    {
        n /= 4;
    }

    // https://en.wikipedia.org/wiki/Legendre%27s_three-square_theorem
    if (n % 8 == 7)
    {
        return 4;
    }

    for (int i = sqrt(n); i > 0; --i)
    {
        if (isSquare(n - i * i))
        {
            return 2;
        }
    }

    return 3;
}
#endif

#ifdef SOLUTION_6
// https://leetcode.com/problems/perfect-squares/discuss/71532/O(sqrt(n))-about-0.034-ms-(and-0.018-ms)
int numSquares(int n)
{
    while (n % 4 == 0)
    {
        n /= 4;
    }

    if (n % 8 == 7)
    {
        return 4;
    }

    int a = -1;
    int b = sqrt(n);
    n -= b * b;
    b += b + 1;
    while (a <= b)
    {
        if (n < 0)
        {
            b -= 2;
            n += b;
        }
        else if (n > 0)
        {
            a += 2;
            n -= a;
        }
        else
        {
            return a < 0 ? 1 : 2;
        }
    }

    return 3;
}
#endif

int amin()
{
    return 0;
}