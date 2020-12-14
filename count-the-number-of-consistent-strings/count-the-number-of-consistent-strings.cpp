#include <string>
#include <vector>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
int countConsistentStrings(string allowed, vector<string> &words)
{
    bool isAllowed[26] = {0};
    for (char c : allowed)
    {
        isAllowed[c - 'a'] = true;
    }

    int count = words.size();
    for (const string &word : words)
    {
        for (char c : word)
        {
            if (!isAllowed[c - 'a'])
            {
                --count;
                break;
            }
        }
    }

    return count;
}
#endif

#ifdef SOLUTION_2
int countConsistentStrings(string allowed, vector<string> &words)
{
    int table = 0;
    for (char c : allowed)
    {
        table |= 1 << (c - 'a');
    }

    int count = words.size();
    for (const string &word : words)
    {
        for (char c : word)
        {
            if (!(table & (1 << (c - 'a'))))
            {
                --count;
                break;
            }
        }
    }

    return count;
}
#endif

int main()
{
    return 0;
}