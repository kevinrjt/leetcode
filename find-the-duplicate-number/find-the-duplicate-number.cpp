#include <algorithm>
#include <vector>

using namespace std;

#define SOLUTION_4

#ifdef SOLUTION_1
int findDuplicate(vector<int> &nums)
{
    vector<char> count(nums.size());
    for (int num : nums)
    {
        if (++count[num] > 1)
        {
            return num;
        }
    }

    return 0;
}
#endif

#ifdef SOLUTION_2
int findDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] == nums[i - 1])
        {
            return nums[i];
        }
    }

    return 0;
}
#endif

#ifdef SOLUTION_3
int findDuplicate(vector<int> &nums)
{
    int low = 1;
    int high = nums.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int cnt = count_if(nums.begin(), nums.end(), [&](int x) { return x <= mid; });
        if (cnt > mid)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}
#endif

#ifdef SOLUTION_4
int findDuplicate(vector<int> &nums)
{
    int slow = 0;
    int fast = 0;
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    int curr = 0;
    do
    {
        slow = nums[slow];
        curr = nums[curr];
    } while (slow != curr);

    return curr;
}
#endif

#ifdef SOLUTION_5
int findDuplicate(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        int index = abs(nums[i]);
        nums[index] = -nums[index];
        if (nums[index] > 0)
        {
            return index;
        }
    }

    return 0;
}
#endif

#ifdef SOLUTION_6
// https://leetcode.com/problems/find-the-duplicate-number/discuss/72872/O(32*N)-solution-using-bit-manipulation-in-10-lines
int findDuplicate(vector<int> &nums)
{
    int duplicate = 0;
    for (int p = 0; p < 32; ++p)
    {
        int bit = 1 << p;
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i & bit)
            {
                ++count1;
            }

            if (nums[i] & bit)
            {
                ++count2;
            }
        }

        if (count1 < count2)
        {
            duplicate += bit;
        }
    }

    return duplicate;
}
#endif

int main()
{
    return 0;
}