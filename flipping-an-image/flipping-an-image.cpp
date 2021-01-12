#include <algorithm>
#include <vector>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
{
    for (auto &row : A)
    {
        reverse(row.begin(), row.end());
        for_each(row.begin(), row.end(), [](int &x) { x = !x; });
    }

    return A;
}
#endif

#ifdef SOLUTION_2
// https://leetcode.com/problems/flipping-an-image/discuss/130590/JavaC%2B%2BPython-Reverse-and-Toggle
vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
{
    int n = A.size();
    for (auto &row : A)
    {
        for (int i = 0, j = n - 1; i <= j; ++i, --j)
        {
            if (row[i] == row[j])
            {
                row[i] = row[j] = !row[j];
            }
        }
    }

    return A;
}
#endif

int main()
{
    return 0;
}