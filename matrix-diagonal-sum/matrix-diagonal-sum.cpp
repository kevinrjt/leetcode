#include <vector>

using namespace std;

int diagonalSum(vector<vector<int>> &mat)
{
    int n = mat.size();
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += mat[i][i] + mat[i][n - 1 - i];
    }

    return n % 2 == 0 ? sum : sum - mat[n / 2][n / 2];
}

int amin()
{
    return 0;
}