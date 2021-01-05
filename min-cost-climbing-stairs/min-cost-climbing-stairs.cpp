#include <algorithm>
#include <vector>

using namespace std;

#define SOLUTION_3

#ifdef SOLUTION_1
int minCostClimbingStairs(vector<int> &cost)
{
    int prevCost = 0;
    int currCost = 0;
    for (int i = 2; i <= cost.size(); ++i)
    {
        int temp = currCost;
        currCost = min(cost[i - 1] + currCost, cost[i - 2] + prevCost);
        prevCost = temp;
    }

    return currCost;
}
#endif

#ifdef SOLUTION_2
int minCostClimbingStairs(vector<int> &cost)
{
    int len = cost.size();
    int prevCost = cost[len - 1];
    int currCost = cost[len - 2];
    for (int i = len - 3; i >= 0; --i)
    {
        int temp = currCost;
        currCost = cost[i] + min(currCost, prevCost);
        prevCost = temp;
    }

    return min(prevCost, currCost);
}
#endif

#ifdef SOLUTION_3
int minCostClimbingStairs(vector<int> &cost)
{
    int prevCost = cost[0];
    int currCost = cost[1];
    for (int i = 2; i < cost.size(); ++i)
    {
        int temp = currCost;
        currCost = cost[i] + min(currCost, prevCost);
        prevCost = temp;
    }

    return min(prevCost, currCost);
}
#endif

int main()
{
    return 0;
}