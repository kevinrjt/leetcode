#include <sstream>
#include <string>

using namespace std;

string countAndSay(int n)
{
    string s = "1";
    for (int i = 2; i <= n; ++i)
    {
        stringstream ss;
        int count = 1;
        char current = s[0];
        for (int i = 1; i < s.length(); ++i)
        {
            if (s[i] != current)
            {
                ss << count << current;
                current = s[i];
                count = 1;
            }
            else
            {
                ++count;
            }
        }

        ss << count << current;
        s = ss.str();
    }

    return s;
}

int main()
{
    return 0;
}