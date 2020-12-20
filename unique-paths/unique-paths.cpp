#include <vector>

using namespace std;

int uniquePaths(int m, int n)
{
    vector<int> table(n, 1);
    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            table[j] += table[j - 1];
        }
    }

    return table[n - 1];
}

int main()
{
    return 0;
}