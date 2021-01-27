#include <algorithm>
#include <vector>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
int lengthOfLIS(vector<int> &nums)
{
    int len = nums.size();
    vector<int> table(len, 1);
    int lis = 0;
    for (int i = 0; i < len; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (nums[j] < nums[i])
            {
                table[i] = max(table[i], table[j] + 1);
            }
        }

        lis = max(lis, table[i]);
    }

    return lis;
}
#endif

#ifdef SOLUTION_2
int lengthOfLIS(vector<int> &nums)
{
    vector<int> table;
    for (int num : nums)
    {
        auto it = lower_bound(table.begin(), table.end(), num);
        if (it == table.end())
        {
            table.push_back(num);
        }
        else
        {
            *it = num;
        }
    }

    return table.size();
}
#endif

int main()
{
    return 0;
}