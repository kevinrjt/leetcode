#include <string>
#include <vector>

using namespace std;

vector<string> fizzBuzz(int n)
{
    vector<string> strs(n);
    for (int i = 1; i <= n; ++i)
    {
        if (i % 3 != 0 && i % 5 != 0)
        {
            strs[i - 1] = to_string(i);
        }
        else
        {
            if (i % 3 == 0)
            {
                strs[i - 1] = "Fizz";
            }

            if (i % 5 == 0)
            {
                strs[i - 1] += "Buzz";
            }
        }
    }

    return strs;
}

int main()
{
    return 0;
}