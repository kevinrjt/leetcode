#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }

    int last = 0;
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] != nums[last])
        {
            nums[++last] = nums[i];
        }
    }

    return last + 1;
}

int main()
{
    return 0;
}