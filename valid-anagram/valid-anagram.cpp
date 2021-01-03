#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

#define SOLUTION_1

#ifdef SOLUTION_1
bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    int count[26] = {};
    for (int i = 0; i < s.length(); ++i)
    {
        ++count[s[i] - 'a'];
        --count[t[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i)
    {
        if (count[i])
        {
            return false;
        }
    }

    return true;
}
#endif

#ifdef SOLUTION_2
// if the inputs contain unicode characters
bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    unordered_map<char, int> count;
    for (int i = 0; i < s.length(); ++i)
    {
        ++count[s[i]];
        --count[t[i]];
    }

    for (auto &p : count)
    {
        if (p.second)
        {
            return false;
        }
    }

    return true;
}
#endif

#ifdef SOLUTION_3
bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}
#endif

int main()
{
    return 0;
}