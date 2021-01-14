#include <algorithm>
#include <vector>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> table(n, INT_MAX);
    table[0] = triangle[0][0];
    for (int i = 1; i < n; ++i)
    {
        int last = INT_MAX;
        for (int j = 0; j <= i; ++j)
        {
            int temp = table[j];
            table[j] = triangle[i][j] + min(last, table[j]);
            last = temp;
        }
    }

    int minSum = INT_MAX;
    for (int s : table)
    {
        minSum = min(minSum, s);
    }

    return minSum;
}
#endif

#ifdef SOLUTION_2
int minimumTotal(vector<vector<int>> &triangle)
{
    vector<int> table(triangle.back());
    for (int i = triangle.size() - 2; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
        {
            table[j] = triangle[i][j] + min(table[j], table[j + 1]);
        }
    }

    return table[0];
}
#endif

int main()
{
    return 0;
}