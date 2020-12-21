#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<int> table(n);
    for (int j = 0; j < n && !obstacleGrid[0][j]; ++j)
    {
        table[j] = 1;
    }

    for (int i = 1; i < m; ++i)
    {
        table[0] = obstacleGrid[i][0] ? 0 : table[0];
        for (int j = 1; j < n; ++j)
        {
            table[j] = obstacleGrid[i][j] ? 0 : table[j] + table[j - 1];
        }
    }

    return table[n - 1];
}

int main()
{
    return 0;
}