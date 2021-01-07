#include <algorithm>
#include <vector>

#include "../utilities.h"

using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    int len = nums.size();
    vector<int> squares(len);
    int i = 0;
    int j = len - 1;
    for (int k = len - 1; k >= 0; --k)
    {
        if (-nums[i] > nums[j])
        {
            squares[k] = nums[i] * nums[i];
            ++i;
        }
        else
        {
            squares[k] = nums[j] * nums[j];
            --j;
        }
    }

    return squares;
}

int main()
{
    vector<int> nums{-7, -3, 2, 3, 11};
    printVector(sortedSquares(nums));
    return 0;
}