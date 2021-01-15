#include <algorithm>
#include <vector>

using namespace std;

int rob(vector<int> &nums)
{
    int prev = 0;
    int curr = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        int temp = curr;
        curr = max(prev + nums[i], curr);
        prev = temp;
    }

    return curr;
}

int main()
{
    return 0;
}