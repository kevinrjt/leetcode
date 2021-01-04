#include <string>

using namespace std;

string toLowerCase(string str)
{
    string lower;
    for (char c : str)
    {
        lower.push_back(c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c);
    }

    return lower;
}

int main()
{
    return 0;
}