#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int minSubarray(vector<int> &nums, int p)
{
    int totalRemainder = 0;
    for (int n : nums)
    {
        totalRemainder = (totalRemainder + n) % p;
    }

    if (totalRemainder == 0)
    {
        return 0;
    }

    int len = nums.size();
    int minLen = len;
    int sumRemainder = 0;
    unordered_map<int, int> remainders{{0, -1}};
    for (int i = 0; i < len; ++i)
    {
        sumRemainder = (sumRemainder + nums[i]) % p;
        int targetRemainder = (sumRemainder - totalRemainder + p) % p;
        auto iter = remainders.find(targetRemainder);
        if (iter != remainders.end())
        {
            minLen = min(minLen, i - iter->second);
        }

        remainders[sumRemainder] = i;
    }

    return minLen == len ? -1 : minLen;
}

int main()
{
    cout << minSubarray(vector<int>{3, 1, 4, 2}, 6) << endl;
    cout << minSubarray(vector<int>{6, 3, 5, 2}, 9) << endl;
    cout << minSubarray(vector<int>{1, 2, 3}, 3) << endl;
    cout << minSubarray(vector<int>{1, 2, 3}, 7) << endl;
    cout << minSubarray(vector<int>{1000000000, 1000000000, 1000000000}, 3) << endl;
    cout << minSubarray(vector<int>{8, 32, 31, 18, 34, 20, 21, 13, 1, 27, 23, 22, 11, 15, 30, 4, 2}, 148) << endl;
    cout << minSubarray(vector<int>{8, 32, 31, 18, 34, 20, 21, 13, 1, 27, 23, 22, 11, 15, 30, 4, 2}, 148000) << endl;
    return 0;
}