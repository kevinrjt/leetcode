#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define SOLUTION_1

#ifdef SOLUTION_1
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_set<int> set;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (!set.insert(nums[i]).second)
        {
            return true;
        }

        if (i >= k)
        {
            set.erase(nums[i - k]);
        }
    }

    return false;
}
#endif

#ifdef SOLUTION_2
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i)
    {
        auto iter = map.find(nums[i]);
        if (iter != map.end() && i - iter->second <= k)
        {
            return true;
        }

        map[nums[i]] = i;
    }

    return false;
}
#endif

int main()
{
    return 0;
}