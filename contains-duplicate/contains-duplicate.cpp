#include <unordered_set>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> set;
    for (int num : nums)
    {
        if (set.find(num) != set.end())
        {
            return true;
        }

        set.insert(num);
    }

    return false;
}

int main()
{
    return 0;
}