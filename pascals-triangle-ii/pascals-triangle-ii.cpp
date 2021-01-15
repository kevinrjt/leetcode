#include <vector>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
vector<int> getRow(int rowIndex)
{
    vector<int> row(rowIndex + 1);
    row[0] = 1;
    for (int i = 1; i <= rowIndex; ++i)
    {
        for (int j = i; j > 0; --j)
        {
            row[j] += row[j - 1];
        }
    }

    return row;
}
#endif

#ifdef SOLUTION_2
// row[i][j] = C(i, j) = i! / (j! * (i - j)!)
vector<int> getRow(int rowIndex)
{
    vector<int> row(rowIndex + 1);
    row[0] = row[rowIndex] = 1;
    long long p = 1;
    for (int j = 1, middle = rowIndex / 2; j <= middle; ++j)
    {
        p = p * (rowIndex - j + 1) / j;
        row[j] = row[rowIndex - j] = p;
    }

    return row;
}
#endif

int main()
{
    return 0;
}