#include <string>

using namespace std;

int countSegments(string s)
{
    int count = s.empty() || s[0] == ' ' ? 0 : 1;
    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] != ' ' && s[i - 1] == ' ')
        {
            ++count;
        }
    }

    return count;
}

int main()
{
    return 0;
}