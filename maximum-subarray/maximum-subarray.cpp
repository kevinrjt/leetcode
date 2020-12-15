#include <algorithm>
#include <vector>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
int maxSubArray(vector<int> &nums, int start, int end)
{
    if (start > end)
    {
        return INT_MIN;
    }

    int mid = start + (end - start) / 2;
    int maxRightSum = 0;
    for (int i = mid + 1, sum = 0; i <= end; ++i)
    {
        sum += nums[i];
        maxRightSum = max(maxRightSum, sum);
    }

    int maxLeftSum = 0;
    for (int i = mid - 1, sum = 0; i >= start; --i)
    {
        sum += nums[i];
        maxLeftSum = max(maxLeftSum, sum);
    }

    int maxSum = nums[mid] + maxRightSum + maxLeftSum;
    maxSum = max(maxSum, maxSubArray(nums, start, mid - 1));
    maxSum = max(maxSum, maxSubArray(nums, mid + 1, end));
    return maxSum;
}

int maxSubArray(vector<int> &nums)
{
    return maxSubArray(nums, 0, nums.size() - 1);
}
#endif

#ifdef SOLUTION_2
int maxSubArray(vector<int> &nums)
{
    int maxSum = INT_MIN;
    int maxSuffixSum = INT_MIN;
    for (int n : nums)
    {
        maxSuffixSum = maxSuffixSum > 0 ? maxSuffixSum + n : n;
        maxSum = max(maxSum, maxSuffixSum);
    }
    return maxSum;
}
#endif

int main()
{
    return 0;
}