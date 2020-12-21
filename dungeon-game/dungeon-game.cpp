#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int calculateMinimumHP(vector<vector<int>> &dungeon)
{
    int m = dungeon.size();
    int n = dungeon[0].size();
    vector<int> minHp(n + 1, INT_MAX);
    minHp[n - 1] = 1;
    for (int i = m - 1; i >= 0; --i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            minHp[j] = max(min(minHp[j], minHp[j + 1]) - dungeon[i][j], 1);
        }
    }

    return minHp[0];
}

int main()
{
    vector<vector<int>> dungeon{{1, -3, 3}, {0, -2, 0}, {-3, -3, -3}};
    cout << calculateMinimumHP(dungeon) << endl;
    return 0;
}