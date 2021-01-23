#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> result;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0, len1 = nums1.size(), len2 = nums2.size();
    while (i < len1 && j < len2)
    {
        if (nums1[i] == nums2[j])
        {
            result.push_back(nums1[i]);
            ++i;
            ++j;
        }
        else if (nums1[i] < nums2[j])
        {
            ++i;
        }
        else
        {
            ++j;
        }
    }

    return result;
}
#endif

#ifdef SOLUTION_2
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> map;
    for (int num : nums1)
    {
        ++map[num];
    }

    vector<int> result;
    for (int num : nums2)
    {
        if (map.find(num) != map.end() && map[num]-- > 0)
        {
            result.push_back(num);
        }
    }

    return result;
}
#endif

int main()
{
    return 0;
}