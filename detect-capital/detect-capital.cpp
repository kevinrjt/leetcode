#include <string>

using namespace std;

#define SOLUTION_1

#ifdef SOLUTION_1
bool detectCapitalUse(string word)
{
    int capitalCount = 0;
    for (char c : word)
    {
        capitalCount += (isupper(c) ? 1 : 0);
    }

    return capitalCount == 0 || capitalCount == word.length() || (capitalCount == 1 && isupper(word[0]));
}
#endif

#ifdef SOLUTION_2
bool detectCapitalUse(string word)
{
    int len = word.length();
    if (len == 1)
    {
        return true;
    }

    if (isupper(word[0]) && isupper(word[1]))
    {
        for (int i = 2; i < len; ++i)
        {
            if (!isupper(word[i]))
            {
                return false;
            }
        }
    }
    else
    {
        for (int i = 1; i < len; ++i)
        {
            if (isupper(word[i]))
            {
                return false;
            }
        }
    }

    return true;
}
#endif

int main()
{
    return 0;
}