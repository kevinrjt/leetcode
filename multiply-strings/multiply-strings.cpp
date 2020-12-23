#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
string multiply(string num1, string num2)
{
    if (num1 == "0" || num2 == "0")
    {
        return "0";
    }

    int len1 = num1.length();
    int len2 = num2.length();
    int carry = 0;
    stringstream ss;
    for (int k = len1 + len2 - 2; k >= 0; --k)
    {
        int digit = carry;
        int start = max(0, k - len2 + 1);
        int end = min(k, len1 - 1);
        for (int i = start; i <= end; ++i)
        {
            digit += (num1[i] - '0') * (num2[k - i] - '0');
        }

        ss << digit % 10;
        carry = digit / 10;
    }

    if (carry > 0)
    {
        ss << carry;
    }

    string product = ss.str();
    reverse(product.begin(), product.end());
    return product;
}
#endif

#ifdef SOLUTION_2
string multiply(string num1, string num2)
{
    if (num1 == "0" || num2 == "0")
    {
        return "0";
    }

    int len1 = num1.length();
    int len2 = num2.length();
    string product(len1 + len2, '0');
    for (int i = len1 - 1; i >= 0; --i)
    {
        for (int j = len2 - 1; j >= 0; --j)
        {
            int digit = (num1[i] - '0') * (num2[j] - '0') + (product[i + j + 1] - '0');
            product[i + j + 1] = (digit % 10) + '0';
            product[i + j] += digit / 10;
        }
    }

    return product[0] == '0' ? product.substr(1) : product;
}
#endif

int main()
{
    return 0;
}