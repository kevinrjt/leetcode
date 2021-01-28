#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
{
    set<long long> window;
    for (int i = 0; i < nums.size(); ++i)
    {
        auto it = window.lower_bound((long long)nums[i] - t);
        if (it != window.end() && *it <= (long long)nums[i] + t)
        {
            return true;
        }

        window.insert(nums[i]);
        if (i >= k)
        {
            window.erase(nums[i - k]);
        }
    }

    return false;
}
#endif

#ifdef SOLUTION_2
bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
{
    unordered_map<long long, long long> table;
    auto getBucket = [t](long long num) { return (num - INT_MIN) / ((long long)t + 1); };
    for (int i = 0; i < nums.size(); ++i)
    {
        long long bucket = getBucket(nums[i]);
        if (table.find(bucket) != table.end())
        {
            return true;
        }

        if (table.find(bucket + 1) != table.end() && table[bucket + 1] - nums[i] <= t)
        {
            return true;
        }

        if (table.find(bucket - 1) != table.end() && nums[i] - table[bucket - 1] <= t)
        {
            return true;
        }

        table[bucket] = nums[i];
        if (i >= k)
        {
            table.erase(getBucket(nums[i - k]));
        }
    }

    return false;
}
#endif

int main()
{
    return 0;
}