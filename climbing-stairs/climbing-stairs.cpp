#include <iostream>

using namespace std;

int climbStairs(int n)
{
    int result = 1;
    int preResult = 1;
    for (int i = 2; i <= n; ++i)
    {
        int temp = result;
        result += preResult;
        preResult = temp;
    }

    return result;
}

int main()
{
    cout << climbStairs(1) << endl;
    cout << climbStairs(2) << endl;
    cout << climbStairs(3) << endl;
    cout << climbStairs(4) << endl;
    cout << climbStairs(5) << endl;
    return 0;
}