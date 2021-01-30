#include <string>

using namespace std;

pair<int, int> toComplexNumber(const string &s)
{
    int real = 0;
    int i = s[0] == '-' ? 1 : 0;
    for (; s[i] != '+'; ++i)
    {
        real = 10 * real + (s[i] - '0');
    }

    int imaginary = 0;
    int j = s[i + 1] == '-' ? i + 2 : i + 1;
    for (; s[j] != 'i'; ++j)
    {
        imaginary = 10 * imaginary + (s[j] - '0');
    }

    real = s[0] == '-' ? -real : real;
    imaginary = s[i + 1] == '-' ? -imaginary : imaginary;
    return {real, imaginary};
}

string complexNumberMultiply(string a, string b)
{
    auto p1 = toComplexNumber(a);
    auto p2 = toComplexNumber(b);
    int real = p1.first * p2.first - p1.second * p2.second;
    int imaginary = p1.first * p2.second + p1.second * p2.first;
    return to_string(real) + "+" + to_string(imaginary) + "i";
}

int main()
{
    return 0;
}