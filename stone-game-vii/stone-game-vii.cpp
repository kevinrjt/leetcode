#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int stoneGameVII(vector<int> &stones)
{
    int len = stones.size();
    vector<int> preSum(len + 1);
    for (int i = 0; i < len; ++i)
    {
        preSum[i + 1] = preSum[i] + stones[i];
    }

    vector<vector<int>> maxDiff(len, vector<int>(len));
    for (int s = 1; s < len; ++s)
    {
        for (int i = 0; i < len - s; ++i)
        {
            int j = i + s;
            maxDiff[i][j] = max(preSum[j + 1] - preSum[i + 1] - maxDiff[i + 1][j], preSum[j] - preSum[i] - maxDiff[i][j - 1]);
        }
    }

    return maxDiff[0][len - 1];
}

int main()
{
    return 0;
}