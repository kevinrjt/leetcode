#include <algorithm>
#include <string>

using namespace std;

int minPartitions(string n)
{
    char maxChar = 0;
    for (char c : n)
    {
        if (c > maxChar)
        {
            maxChar = c;
        }
    }

    return maxChar - '0';
}

int main()
{
    return 0;
}