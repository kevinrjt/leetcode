#include <algorithm>
#include <vector>

using namespace std;

#define SOLUTION_1

#ifdef SOLUTION_1
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (matrix.empty() || matrix[0].empty())
    {
        return false;
    }

    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0;
    int high = m;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (matrix[mid][n - 1] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    if (low == m)
    {
        return false;
    }

    auto pos = lower_bound(matrix[low].begin(), matrix[low].end(), target);
    return pos != matrix[low].end() && *pos == target;
}
#endif

#ifdef SOLUTION_2
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (matrix.empty() || matrix[0].empty())
    {
        return false;
    }

    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0;
    int high = m * n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int i = mid / n;
        int j = mid % n;
        if (matrix[i][j] < target)
        {
            low = mid + 1;
        }
        else if (matrix[i][j] > target)
        {
            high = mid - 1;
        }
        else
        {
            return true;
        }
    }

    return false;
}
#endif

int main()
{
    return 0;
}