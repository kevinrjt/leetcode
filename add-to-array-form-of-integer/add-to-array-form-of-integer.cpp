#include <vector>

using namespace std;

vector<int> addToArrayForm(vector<int> &A, int K)
{
    vector<int> sum;
    int i = A.size() - 1;
    while (i >= 0 || K)
    {
        int s = K + (i >= 0 ? A[i--] : 0);
        sum.push_back(s % 10);
        K = s / 10;
    }

    reverse(sum.begin(), sum.end());
    return sum;
}

int main()
{
    return 0;
}