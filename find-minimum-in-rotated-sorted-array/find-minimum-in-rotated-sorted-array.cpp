#include <algorithm>
#include <vector>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
int findMin(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;
    while (nums[low] > nums[high])
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

    return nums[low];
}
#endif

#ifdef SOLUTION_2
int findMin(vector<int> &nums)
{
    return *lower_bound(nums.begin(), nums.end(), nums.back(), [&](int x, int y) { return x > y; });
}
#endif

int main()
{
    return 0;
}