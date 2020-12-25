#include <vector>

using namespace std;

void setRow(vector<vector<int>> &matrix, int i)
{
    for (int j = 0; j < matrix[0].size(); ++j)
    {
        matrix[i][j] = 0;
    }
}

void setCol(vector<vector<int>> &matrix, int j)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        matrix[i][j] = 0;
    }
}

void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    bool setFirstRow = false;
    for (int j = 0; j < n; ++j)
    {
        if (matrix[0][j] == 0)
        {
            setFirstRow = true;
            break;
        }
    }

    bool setFirstCol = false;
    for (int i = 0; i < m; ++i)
    {
        if (matrix[i][0] == 0)
        {
            setFirstCol = true;
            break;
        }
    }

    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = matrix[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < m; ++i)
    {
        if (matrix[i][0] == 0)
        {
            setRow(matrix, i);
        }
    }

    for (int j = 1; j < n; ++j)
    {
        if (matrix[0][j] == 0)
        {
            setCol(matrix, j);
        }
    }

    if (setFirstRow)
    {
        setRow(matrix, 0);
    }

    if (setFirstCol)
    {
        setCol(matrix, 0);
    }
}

int main()
{
    return 0;
}