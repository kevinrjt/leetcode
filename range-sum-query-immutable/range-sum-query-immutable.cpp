#include <vector>

using namespace std;

class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        int len = nums.size();
        prefixSum = vector<int>(len + 1);
        for (int i = 0; i < len; ++i)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
    }

    int sumRange(int i, int j)
    {
        return prefixSum[j + 1] - prefixSum[i];
    }

private:
    vector<int> prefixSum;
};

int main()
{
    return 0;
}