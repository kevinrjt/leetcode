#include <vector>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i)
    {
        for (int j = i; j < n - 1 - i; ++j)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = temp;
        }
    }
}
#endif

#ifdef SOLUTION_2
void rotate(vector<vector<int>> &matrix)
{
    reverse(matrix.begin(), matrix.end());
    int n = matrix.size();
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
#endif

int main()
{
    return 0;
}