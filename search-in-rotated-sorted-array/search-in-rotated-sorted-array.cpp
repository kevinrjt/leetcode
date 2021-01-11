#include <algorithm>
#include <vector>

using namespace std;

#define SOLUTION_4

#ifdef SOLUTION_1
int search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (target == nums[mid])
        {
            return mid;
        }

        if (nums[mid] < nums[high])
        {
            if (target < nums[mid] || target > nums[high])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (target < nums[mid] && target > nums[high])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }

    return -1;
}
#endif

#ifdef SOLUTION_2
int search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (target == nums[mid])
        {
            return mid;
        }

        if (nums[mid] < nums[0])
        {
            if (target < nums[mid] || target >= nums[0])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (target < nums[mid] && target >= nums[0])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }

    return -1;
}
#endif

#ifdef SOLUTION_3
// Same as SOLUTION_2: https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14419/Pretty-short-C%2B%2BJavaRubyPython
int search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (target == nums[mid])
        {
            return mid;
        }
        else if ((nums[mid] < nums[0]) ^ (target > nums[mid]) ^ (target < nums[0]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}
#endif

#ifdef SOLUTION_4
// Revised from SOLUTION_2. Another explanation: https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14435/Clever-idea-making-it-simple
int search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (target == nums[mid])
        {
            return mid;
        }

        int val = (nums[mid] < nums[0]) == (target < nums[0])
                      ? nums[mid]
                      : (target < nums[0] ? INT_MIN : INT_MAX);
        if (target < val)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}
#endif

#ifdef SOLUTION_5
// Same as SOLUTION_4: https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14443/C%2B%2B-4-lines-4ms
int search(vector<int> &nums, int target)
{
    auto skip_left = [&](int x) { return x >= nums[0] ? INT_MIN : x; };
    auto skip_right = [&](int x) { return x < nums[0] ? INT_MAX : x; };
    auto adjust = [&](int x) { return target < nums[0] ? skip_left(x) : skip_right(x); };
    auto it = lower_bound(nums.begin(), nums.end(), target, [&](int x, int y) { return adjust(x) < adjust(y); });
    return it != nums.end() && *it == target ? it - nums.begin() : -1;
}
#endif

#ifdef SOLUTION_6
int search(vector<int> &nums, int target)
{
    int len = nums.size();
    int low = 0;
    int high = len - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    if (target > nums[len - 1])
    {
        int pos = lower_bound(nums.begin(), nums.begin() + low, target) - nums.begin();
        return nums[pos] == target ? pos : -1;
    }
    else
    {
        int pos = lower_bound(nums.begin() + low, nums.end(), target) - nums.begin();
        return pos < len && nums[pos] == target ? pos : -1;
    }
}
#endif

#ifdef SOLUTION_7
// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14425/Concise-O(log-N)-Binary-search-solution
int search(vector<int> &nums, int target)
{
    int len = nums.size();
    int low = 0;
    int high = len - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    int offset = low;
    low = 0;
    high = len - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int pos = (mid + offset) % len;
        if (nums[pos] < target)
        {
            low = mid + 1;
        }
        else if (nums[pos] > target)
        {
            high = mid - 1;
        }
        else
        {
            return pos;
        }
    }

    return -1;
}
#endif

int main()
{
    return 0;
}