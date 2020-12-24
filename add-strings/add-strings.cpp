#include <string>
#include <sstream>

using namespace std;

string addStrings(string num1, string num2)
{
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;
    stringstream ss;
    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        sum += i >= 0 ? num1[i--] - '0' : 0;
        sum += j >= 0 ? num2[j--] - '0' : 0;
        ss << sum % 10;
        carry = sum / 10;
    }

    string sumStr = ss.str();
    reverse(sumStr.begin(), sumStr.end());
    return sumStr;
}

int main()
{
    return 0;
}