#include <iostream>
#include <string>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
bool isIsomorphic(string s, string t)
{
    char table1[128] = {0};
    char table2[128] = {0};
    for (int i = 0; i < s.length(); ++i)
    {
        if (table1[s[i]] == 0 && table2[t[i]] == 0)
        {
            table1[s[i]] = t[i];
            table2[t[i]] = s[i];
        }
        else if (table1[s[i]] != t[i] || table2[t[i]] != s[i])
        {
            return false;
        }
    }

    return true;
}
#endif

#ifdef SOLUTION_2
bool isIsomorphic(string s, string t)
{
    char table1[128] = {0};
    char table2[128] = {0};
    for (int i = 0; i < s.length(); ++i)
    {
        if (table1[s[i]] != table2[t[i]])
        {
            return false;
        }

        table1[s[i]] = i + 1;
        table2[t[i]] = i + 1;
    }

    return true;
}
#endif

int main()
{
    cout << isIsomorphic("add", "egg") << endl;
    cout << isIsomorphic("foo", "bar") << endl;
    cout << isIsomorphic("paper", "title") << endl;
    cout << isIsomorphic("ard", "ege") << endl;
    cout << isIsomorphic("ege", "ard") << endl;
    cout << isIsomorphic("adrd", "efge") << endl;
    return 0;
}