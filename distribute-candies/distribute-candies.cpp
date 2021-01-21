#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

int distributeCandies(vector<int> &candyType)
{
    return min(candyType.size() / 2, unordered_set(candyType.begin(), candyType.end()).size());
}

int main()
{
    return 0;
}