#include <vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
{
    int m = nums.size();
    int n = nums[0].size();
    if (m * n != r * c)
    {
        return nums;
    }

    vector<vector<int>> reshaped(r, vector<int>(c));
    int k = 0;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            reshaped[i][j] = nums[k / n][k % n];
            ++k;
        }
    }

    return reshaped;
}

int main()
{
    return 0;
}