#include <sstream>
#include <string>

using namespace std;

#define SOLUTION_1

#ifdef SOLUTION_1
string intToRoman(int digit, char s1, char s5, char s10)
{
    if (digit < 4)
    {
        return string(digit, s1);
    }
    else if (digit == 4)
    {
        return string(1, s1) + s5;
    }
    else if (digit < 9)
    {
        return s5 + string(digit - 5, s1);
    }
    else
    {
        return string(1, s1) + s10;
    }
}

string intToRoman(int num)
{
    return string(num / 1000, 'M') + intToRoman((num / 100) % 10, 'C', 'D', 'M') + intToRoman((num / 10) % 10, 'X', 'L', 'C') + intToRoman(num % 10, 'I', 'V', 'X');
}
#endif

#ifdef SOLUTION_2
string intToRoman(int num)
{
    string thousands[4] = {"", "M", "MM", "MMM"};
    string hundreds[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string tens[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string ones[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return thousands[num / 1000] + hundreds[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
}
#endif

#ifdef SOLUTION_3
string intToRoman(int num)
{
    int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string strs[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    stringstream ss;
    for (int i = 0; i < 13; ++i)
    {
        while (num >= values[i])
        {
            num -= values[i];
            ss << strs[i];
        }
    }

    return ss.str();
}
#endif

int main()
{
    return 0;
}