#include <algorithm>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); ++i)
    {
        maxProfit += max(0, prices[i] - prices[i - 1]);
    }

    return maxProfit;
}

int main()
{
    return 0;
}