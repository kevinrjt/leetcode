#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define SOLUTION_3

#ifdef SOLUTION_1
int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int coin : coins)
    {
        for (int j = coin; j <= amount; ++j)
        {
            dp[j] = min(1 + dp[j - coin], dp[j]);
        }
    }

    return dp[amount] <= amount ? dp[amount] : -1;
}
#endif

#ifdef SOLUTION_2
int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
    {
        return 0;
    }

    queue<int> q;
    q.push(amount);
    vector<char> visited(amount + 1);
    visited[amount] = true;
    int count = 0;
    while (!q.empty())
    {
        ++count;
        for (int i = q.size(); i > 0; --i)
        {
            amount = q.front();
            q.pop();
            for (int coin : coins)
            {
                if (amount == coin)
                {
                    return count;
                }
                else if (amount > coin && !visited[amount - coin])
                {
                    q.push(amount - coin);
                    visited[amount - coin] = true;
                }
            }
        }
    }

    return -1;
}
#endif

#ifdef SOLUTION_3
void dfs(vector<int> &coins, int amount, int index, int count, int &result)
{
    if (index < 0)
    {
        return;
    }

    int n = amount / coins[index];
    if (count + n >= result)
    {
        return;
    }

    if (amount == n * coins[index])
    {
        result = count + n;
        return;
    }

    for (int i = n; i >= 0; --i)
    {
        int remaining = amount - i * coins[index];
        dfs(coins, remaining, index - 1, count + i, result);
    }
}

int coinChange(vector<int> &coins, int amount)
{
    sort(coins.begin(), coins.end());
    int result = amount + 1;
    dfs(coins, amount, coins.size() - 1, 0, result);
    return result <= amount ? result : -1;
}
#endif

int main()
{
    vector<int> coins{1, 9, 10};
    cout << coinChange(coins, 38) << endl;
    return 0;
}