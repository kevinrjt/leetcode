#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

#define SOLUTION_1

#ifdef SOLUTION_1
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> result;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0, len1 = nums1.size(), len2 = nums2.size();
    while (i < len1 && j < len2)
    {
        if (nums1[i] == nums2[j])
        {
            if (result.empty() || nums1[i] != result.back())
            {
                result.push_back(nums1[i]);
            }

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
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> result;
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    for (int num : set2)
    {
        if (set1.find(num) != set1.end())
        {
            result.push_back(num);
        }
    }

    return result;
}
#endif

#ifdef SOLUTION_3
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> result;
    sort(nums1.begin(), nums1.end());
    for (int num : nums2)
    {
        if (binary_search(nums1.begin(), nums1.end(), num))
        {
            result.insert(num);
        }
    }

    return vector<int>(result.begin(), result.end());
}
#endif

#ifdef SOLUTION_4
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> set(nums1.begin(), nums1.end());
    vector<int> result;
    for (int num : nums2)
    {
        if (set.erase(num))
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