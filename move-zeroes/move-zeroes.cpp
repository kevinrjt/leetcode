#include <algorithm>
#include <vector>

using namespace std;

#define SOLUTION_1

#ifdef SOLUTION_1
void moveZeroes(vector<int> &nums)
{
    int len = nums.size();
    for (int i = 0, j = 0; j < len; ++j)
    {
        if (nums[j])
        {
            swap(nums[i++], nums[j]);
        }
    }
}
#endif

#ifdef SOLUTION_2
void moveZeroes(vector<int> &nums)
{
    int i = 0;
    int len = nums.size();
    for (int j = 0; j < len; ++j)
    {
        if (nums[j])
        {
            nums[i++] = nums[j];
        }
    }

    for (; i < len; ++i)
    {
        nums[i] = 0;
    }
}
#endif

#ifdef SOLUTION_3
void moveZeroes(vector<int> &nums)
{
    fill(remove(nums.begin(), nums.end(), 0), nums.end(), 0);
}
#endif

int main()
{
    return 0;
}