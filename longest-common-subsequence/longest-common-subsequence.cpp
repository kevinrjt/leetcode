#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.length();
    int n = text2.length();
    vector<int> table(n + 1);
    for (int i = 1; i <= m; ++i)
    {
        int last = 0;
        for (int j = 1; j <= n; ++j)
        {
            int temp = table[j];
            table[j] = text1[i - 1] == text2[j - 1] ? 1 + last : max(table[j - 1], table[j]);
            last = temp;
        }
    }

    return table[n];
}

int main()
{
    return 0;
}