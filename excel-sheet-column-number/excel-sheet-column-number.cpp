#include <string>

using namespace std;

int titleToNumber(string s)
{
    int num = 0;
    for (char c : s)
    {
        num = 26 * num + (c - 'A' + 1);
    }

    return num;
}

int main()
{
    return 0;
}