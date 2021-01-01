#include <string>

using namespace std;

string convertToTitle(int n)
{
    string str;
    while (n > 0)
    {
        str.append(1, (n - 1) % 26 + 'A');
        n = (n - 1) / 26;
    }

    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    return 0;
}