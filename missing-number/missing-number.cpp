#include <algorithm>
#include <vector>

using namespace std;

#define SOLUTION_3

#ifdef SOLUTION_1
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int s = n * (n + 1) / 2;
    for (int i : nums)
    {
        s -= i;
    }

    return s;
}
#endif

#ifdef SOLUTION_2
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int len = n;
    for (int i = 0; i < len; ++i)
    {
        n ^= i ^ nums[i];
    }

    return n;
}
#endif

#ifdef SOLUTION_3
int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int low = 0;
    int high = nums.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == mid)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}
#endif

int main()
{
    return 0;
}