#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

#define SOLUTION_1

#ifdef SOLUTION_1
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> table;
    for (int i = 0; i < nums.size(); ++i)
    {
        int t = target - nums[i];
        if (table.find(t) != table.end())
        {
            return {table[t], i};
        }

        table[nums[i]] = i;
    }

    return {};
}
#endif

#ifdef SOLUTION_2
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> copy(nums);
    sort(copy.begin(), copy.end());
    int low = 0;
    int high = copy.size() - 1;
    while (low < high)
    {
        int s = copy[low] + copy[high];
        if (s == target)
        {
            break;
        }
        else if (s > target)
        {
            --high;
        }
        else
        {
            ++low;
        }
    }

    vector<int> indices;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == copy[low] || nums[i] == copy[high])
        {
            indices.push_back(i);
        }
    }

    return indices;
}
#endif

int main()
{
    return 0;
}