#include <algorithm>
#include <vector>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
int peakIndexInMountainArray(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}
#endif

#ifdef SOLUTION_2
// https://leetcode.com/problems/peak-index-in-a-mountain-array/discuss/139848/C%2B%2BJavaPython-Better-than-Binary-Search
// https://en.wikipedia.org/wiki/Golden-section_search
int peakIndexInMountainArray(vector<int> &arr)
{
    auto gold1 = [](int low, int high) { return low + int(round(0.382 * (high - low))); };
    auto gold2 = [](int low, int high) { return low + int(round(0.618 * (high - low))); };
    int low = 0;
    int high = arr.size() - 1;
    int x1 = gold1(low, high);
    int x2 = gold2(low, high);
    while (x1 < x2)
    {
        if (arr[x1] < arr[x2])
        {
            low = x1;
            x1 = x2;
            x2 = gold2(low, high);
        }
        else
        {
            high = x2;
            x2 = x1;
            x1 = gold1(low, high);
        }
    }

    return max_element(arr.begin() + low, arr.begin() + high + 1) - arr.begin();
}
#endif

int main()
{
    return 0;
}