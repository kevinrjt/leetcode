#include <vector>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
int removeElement(vector<int> &nums, int val)
{
    int len = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != val)
        {
            nums[len++] = nums[i];
        }
    }

    return len;
}
#endif

#ifdef SOLUTION_2
int removeElement(vector<int> &nums, int val)
{
    int len = nums.size();
    int i = 0;
    while (i < len)
    {
        if (nums[i] == val)
        {
            nums[i] = nums[--len];
        }
        else
        {
            i++;
        }
    }

    return len;
}
#endif

int main()
{
    return 0;
}