#include <string>

using namespace std;

int numJewelsInStones(string J, string S)
{
    bool table[128] = {0};
    for (char j : J)
    {
        table[j] = 1;
    }

    int count = 0;
    for (char s : S)
    {
        count += table[s];
    }

    return count;
}

int main()
{
    return 0;
}