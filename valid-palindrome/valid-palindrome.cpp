#include <string>

using namespace std;

bool isPalindrome(string s)
{
    for (int i = 0, j = s.length() - 1; i < j; ++i, --j)
    {
        for (; i < j && !isalnum(s[i]); ++i)
            ;
        for (; j > i && !isalnum(s[j]); --j)
            ;
        if (tolower(s[i]) != tolower(s[j]))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    return 0;
}