#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int maxLen = 0;
    vector<int> table(256, -1);
    for (int i = 0, j = -1; i < s.length(); ++i)
    {
        if (j < table[s[i]])
        {
            j = table[s[i]];
        }
        else
        {
            maxLen = max(maxLen, i - j);
        }

        table[s[i]] = i;
    }

    return maxLen;
}

int main()
{
    return 0;
}