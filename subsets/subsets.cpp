#include <vector>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> sets(1);
    for (int n : nums)
    {
        int len = sets.size();
        for (int i = 0; i < len; ++i)
        {
            sets.push_back(sets[i]);
            sets.back().push_back(n);
        }
    }

    return sets;
}
#endif

#ifdef SOLUTION_2
vector<vector<int>> subsets(vector<int> &nums)
{
    int len = nums.size();
    int totalSets = 1 << len;
    vector<vector<int>> sets(totalSets);
    for (int i = 0; i < len; ++i)
    {
        for (int step = 1 << i, start = step; start < totalSets; start += 2 * step)
        {
            for (int j = start; j < start + step; ++j)
            {
                sets[j].push_back(nums[i]);
            }
        }
    }

    return sets;
}
#endif

#ifdef SOLUTION_3
void subsets(vector<int> &nums, int start, vector<int> &set, vector<vector<int>> &sets)
{
    sets.push_back(set);
    for (int i = start; i < nums.size(); ++i)
    {
        set.push_back(nums[i]);
        subsets(nums, i + 1, set, sets);
        set.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> sets;
    vector<int> set;
    subsets(nums, 0, set, sets);
    return sets;
}
#endif

int main()
{
    return 0;
}