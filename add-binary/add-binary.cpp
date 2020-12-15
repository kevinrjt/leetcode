#include <sstream>
#include <string>

using namespace std;

string addBinary(string a, string b)
{
    stringstream ss;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    while (i >= 0 || j >= 0)
    {
        int sum = carry;
        sum += i >= 0 ? a[i--] - '0' : 0;
        sum += j >= 0 ? b[j--] - '0' : 0;
        ss << sum % 2;
        carry = sum / 2;
    }

    if (carry > 0)
    {
        ss << carry;
    }

    string sumStr = ss.str();
    reverse(sumStr.begin(), sumStr.end());
    return sumStr;
}

int main()
{
    return 0;
}