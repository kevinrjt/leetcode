#include <string>

using namespace std;

int romanToInt(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

int romanToInt(string s)
{
    int val = 0;
    int last = 0;
    for (char c : s)
    {
        int current = romanToInt(c);
        if (current > last)
        {
            val -= 2 * last;
        }

        val += current;
        last = current;
    }

    return val;
}

int main()
{
    return 0;
}