#include <algorithm>
#include <vector>

using namespace std;

#define SOLUTION_6

#ifdef SOLUTION_1
void rotate(vector<int> &nums, int k)
{
    k %= nums.size();
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end());
}
#endif

#ifdef SOLUTION_2
void rotate(vector<int> &nums, int k)
{
    int len = nums.size();
    k %= len;
    vector<int> temp(nums.begin() + len - k, nums.end());
    for (int i = len - 1; i >= k; --i)
    {
        nums[i] = nums[i - k];
    }

    for (int i = 0; i < k; ++i)
    {
        nums[i] = temp[i];
    }
}
#endif

#ifdef SOLUTION_3
void rotate(vector<int> &nums, int k)
{
    int len = nums.size();
    k %= len;
    int start = 0;
    while (k > 0)
    {
        int m = len - start - k;
        for (int i = start; i < start + k; ++i)
        {
            swap(nums[i], nums[i + m]);
        }

        start += k;
        k %= m;
    }
}
#endif

#ifdef SOLUTION_4
// Same as SOLUTION_3: https://leetcode.com/problems/rotate-array/discuss/54263/3-lines-of-C%2B%2B-in-one-pass-using-swap
void rotate(vector<int> &nums, int k)
{
    for (int start = 0, n = nums.size(); k %= n; start += k, n -= k)
    {
        for (int i = start; i < start + k; ++i)
        {
            swap(nums[i], nums[i + n - k]);
        }
    }
}
#endif

#ifdef SOLUTION_5
// http://www.cplusplus.com/reference/algorithm/rotate/
void rotate(vector<int> &nums, int k)
{
    int len = nums.size();
    int pivot = len - k % len;
    if (pivot == len)
    {
        return;
    }

    int first = 0;
    int next = pivot;
    while (first != next)
    {
        swap(nums[first++], nums[next++]);
        if (next == len)
        {
            next = pivot;
        }
        else if (first == pivot)
        {
            pivot = next;
        }
    }
}
#endif

#ifdef SOLUTION_6
void rotate(vector<int> &nums, int k)
{
    for (int i = 0, count = 0, len = nums.size(); count < len; ++i)
    {
        int pos = i;
        int val = nums[i];
        do
        {
            pos = (pos + k) % len;
            int temp = nums[pos];
            nums[pos] = val;
            val = temp;
            ++count;
        } while (pos != i);
    }
}
#endif

int main()
{
    return 0;
}