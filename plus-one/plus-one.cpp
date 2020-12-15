#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    vector<int> result(digits);
    for (int i = digits.size() - 1; i >= 0; --i)
    {
        if (digits[i] < 9)
        {
            ++result[i];
            return result;
        }

        result[i] = 0;
    }

    result[0] = 1;
    result.push_back(0);
    return result;
}

int main()
{
    return 0;
}