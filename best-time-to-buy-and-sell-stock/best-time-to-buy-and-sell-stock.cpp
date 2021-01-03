#include <algorithm>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i)
    {
        profit = max(0, prices[i] - prices[i - 1] + profit);
        maxProfit = max(maxProfit, profit);
    }

    return maxProfit;
}

int main()
{
    return 0;
}