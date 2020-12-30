#include <vector>

using namespace std;

#define SOLUTION_3

#ifdef SOLUTION_1
void combine(int k, int start, int end, vector<int> &combination, vector<vector<int>> &combinations)
{
    if (k == 0)
    {
        combinations.push_back(combination);
        return;
    }

    for (int i = start; i <= end; ++i)
    {
        combination.push_back(i);
        combine(k - 1, i + 1, end + 1, combination, combinations);
        combination.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> combinations;
    vector<int> combination;
    combine(k, 1, n - k + 1, combination, combinations);
    return combinations;
}
#endif

#ifdef SOLUTION_2
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> combinations(1);
    for (int i = 0; i < k; ++i)
    {
        vector<vector<int>> temp(move(combinations));
        for (auto &combination : temp)
        {
            int start = i == 0 ? 1 : combination[i - 1] + 1;
            int end = n - k + i + 1;
            for (int j = start; j <= end; ++j)
            {
                combination.push_back(j);
                combinations.push_back(combination);
                combination.pop_back();
            }
        }
    }

    return combinations;
}
#endif

#ifdef SOLUTION_3
// https://leetcode.com/problems/combinations/discuss/26992/Short-Iterative-C%2B%2B-Answer-8ms
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> combinations;
    vector<int> combination(k);
    int i = 0;
    while (i >= 0)
    {
        combination[i]++;
        if (combination[i] > n - k + 1 + i)
        {
            --i;
        }
        else if (i == k - 1)
        {
            combinations.push_back(combination);
        }
        else
        {
            ++i;
            combination[i] = combination[i - 1];
        }
    }

    return combinations;
}
#endif

#ifdef SOLUTION_4
vector<vector<int>> combine(int n, int k)
{
    vector<vector<vector<int>>> table = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(1));
    for (int i = 1; i <= k; ++i)
    {
        vector<vector<int>> last(move(table[i - 1]));
        for (int j = i; j <= n; ++j)
        {
            vector<vector<int>> temp(move(table[j]));
            table[j] = j == i ? vector<vector<int>>() : table[j - 1];
            for (auto &combination : last)
            {
                combination.push_back(j);
                table[j].push_back(move(combination));
            }

            last = move(temp);
        }
    }

    return table[n];
}
#endif

int main()
{
    return 0;
}