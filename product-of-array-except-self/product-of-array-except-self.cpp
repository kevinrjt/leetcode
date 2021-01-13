#include <vector>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
vector<int> productExceptSelf(vector<int> &nums)
{
    int len = nums.size();
    vector<int> result(len);
    result[0] = 1;
    for (int i = 1; i < len; ++i)
    {
        result[i] = result[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for (int i = len - 2; i >= 0; --i)
    {
        suffix *= nums[i + 1];
        result[i] *= suffix;
    }

    return result;
}
#endif

#ifdef SOLUTION_2
vector<int> productExceptSelf(vector<int> &nums)
{
    int len = nums.size();
    vector<int> result(len, 1);
    int prefix = 1;
    int suffix = 1;
    for (int i = 0; i < len; ++i)
    {
        result[i] *= prefix;
        result[len - 1 - i] *= suffix;
        prefix *= nums[i];
        suffix *= nums[len - 1 - i];
    }

    return result;
}
#endif

int main()
{
    return 0;
}