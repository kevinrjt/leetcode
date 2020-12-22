#include <algorithm>
#include <vector>

using namespace std;

void sortColors(vector<int> &nums)
{
    int i = 0;
    int j = nums.size();
    int k = 0;
    while (k < j)
    {
        if (nums[k] == 0)
        {
            swap(nums[i++], nums[k++]);
        }
        else if (nums[k] == 1)
        {
            ++k;
        }
        else
        {
            swap(nums[k], nums[--j]);
        }
    }
}

int main()
{
    return 0;
}