#include <vector>

using namespace std;

vector<vector<int>> transpose(vector<vector<int>> &A)
{
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> T(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            T[i][j] = A[j][i];
        }
    }

    return T;
}

int main()
{
    return 0;
}