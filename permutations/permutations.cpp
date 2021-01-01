#include <vector>

using namespace std;

#define SOLUTION_3

#ifdef SOLUTION_1
void permute(vector<int> &nums, int k, int mask, vector<int> &permutation, vector<vector<int>> &permutations)
{
    if (k == 0)
    {
        permutations.push_back(permutation);
        return;
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        int bit = 1 << i;
        if (!(mask & bit))
        {
            permutation.push_back(nums[i]);
            mask |= bit;
            permute(nums, k - 1, mask, permutation, permutations);
            permutation.pop_back();
            mask ^= bit;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> permutations;
    vector<int> permutation;
    permute(nums, nums.size(), 0, permutation, permutations);
    return permutations;
}
#endif

#ifdef SOLUTION_2
void permute(vector<int> &nums, int start, vector<vector<int>> &permutations)
{
    if (start == nums.size() - 1)
    {
        permutations.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); ++i)
    {
        swap(nums[start], nums[i]);
        permute(nums, start + 1, permutations);
        swap(nums[start], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> permutations;
    permute(nums, 0, permutations);
    return permutations;
}
#endif

#ifdef SOLUTION_3
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> permutations(1);
    for (int i = 0; i < nums.size(); ++i)
    {
        int len = permutations.size();
        for (int j = 0; j < len; ++j)
        {
            permutations[j].push_back(nums[i]);
            for (int k = 0; k < i; ++k)
            {
                swap(permutations[j][i], permutations[j][k]);
                permutations.push_back(permutations[j]);
                swap(permutations[j][i], permutations[j][k]);
            }
        }
    }

    return permutations;
}
#endif

int main()
{
    return 0;
}