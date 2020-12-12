#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
    {
        return "";
    }

    for (int j = 0; j < strs[0].size(); ++j)
    {
        char c = strs[0][j];
        for (int i = 1; i < strs.size(); ++i)
        {
            if (j >= strs[i].size() || strs[i][j] != c)
            {
                return strs[0].substr(0, j);
            }
        }
    }

    return strs[0];
}

int main()
{
    return 0;
}