#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> triplets;
    sort(nums.begin(), nums.end());
    int len = nums.size();
    for (int i = 0; i < len - 2; ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int j = i + 1;
        int k = len - 1;
        while (j < k)
        {
            int s = nums[j] + nums[k];
            if (s == -nums[i])
            {
                triplets.push_back({nums[i], nums[j++], nums[k--]});
                while (j < k && nums[j] == nums[j - 1] && nums[k] == nums[k + 1])
                {
                    ++j;
                    --k;
                }
            }
            else if (s < -nums[i])
            {
                ++j;
            }
            else
            {
                --k;
            }
        }
    }

    return triplets;
}

int main()
{
    return 0;
}