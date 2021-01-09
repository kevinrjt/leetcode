#include <algorithm>
#include <vector>

using namespace std;

#define SOLUTION_3

#ifdef SOLUTION_1
vector<int> searchRange(vector<int> &nums, int target)
{
    int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (start == nums.size() || nums[start] != target)
    {
        return {-1, -1};
    }

    int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    return {start, end};
}
#endif

#ifdef SOLUTION_2
vector<int> searchRange(vector<int> &nums, int target)
{
    int len = nums.size();
    int low = 0;
    int high = len;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    if (low == len || nums[low] != target)
    {
        return {-1, -1};
    }

    int start = low;
    high = len - 1;
    while (low < high)
    {
        int mid = low + (high - low + 1) / 2;
        if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid;
        }
    }

    return {start, high};
}
#endif

#ifdef SOLUTION_3
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/14707/9-11-lines-O(log-n)
vector<int> searchRange(vector<int> &nums, int low, int high, int target)
{
    if (low > high || nums[low] > target || nums[high] < target)
    {
        return {-1, -1};
    }
    else if (nums[low] == target && nums[high] == target)
    {
        return {low, high};
    }

    int mid = low + (high - low) / 2;
    vector<int> left = searchRange(nums, low, mid, target);
    vector<int> right = searchRange(nums, mid + 1, high, target);
    if (left[0] < 0)
    {
        return right;
    }
    else if (right[1] < 0)
    {
        return left;
    }

    return {left[0], right[1]};
}

vector<int> searchRange(vector<int> &nums, int target)
{
    return searchRange(nums, 0, nums.size() - 1, target);
}
#endif

int main()
{
    return 0;
}