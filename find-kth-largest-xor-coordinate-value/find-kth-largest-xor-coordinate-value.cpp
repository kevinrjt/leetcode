#include <queue>
#include <vector>

using namespace std;

#define SOLUTION_4

#ifdef SOLUTION_1
int kthLargestValue(vector<vector<int>> &matrix, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i > 0 && j > 0)
            {
                matrix[i][j] ^= matrix[i][j - 1] ^ matrix[i - 1][j] ^ matrix[i - 1][j - 1];
            }
            else if (i > 0)
            {
                matrix[i][j] ^= matrix[i - 1][j];
            }
            else if (j > 0)
            {
                matrix[i][j] ^= matrix[i][j - 1];
            }

            if (pq.size() < k)
            {
                pq.push(matrix[i][j]);
            }
            else if (matrix[i][j] > pq.top())
            {
                pq.pop();
                pq.push(matrix[i][j]);
            }
        }
    }

    return pq.top();
}
#endif

#ifdef SOLUTION_2
int kthLargestValue(vector<vector<int>> &matrix, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            matrix[i][j] ^= matrix[i][j - 1];
        }
    }

    for (int j = 0; j < n; ++j)
    {
        for (int i = 1; i < m; ++i)
        {
            matrix[i][j] ^= matrix[i - 1][j];
        }
    }

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (pq.size() < k)
            {
                pq.push(matrix[i][j]);
            }
            else if (matrix[i][j] > pq.top())
            {
                pq.pop();
                pq.push(matrix[i][j]);
            }
        }
    }

    return pq.top();
}
#endif

#ifdef SOLUTION_3
int kthLargestValue(vector<vector<int>> &matrix, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> dp(n);
    for (int i = 0; i < m; ++i)
    {
        int cols = 0;
        for (int j = 0; j < n; ++j)
        {
            cols ^= matrix[i][j];
            dp[j] ^= cols;
            if (pq.size() < k)
            {
                pq.push(dp[j]);
            }
            else if (dp[j] > pq.top())
            {
                pq.pop();
                pq.push(dp[j]);
            }
        }
    }

    return pq.top();
}
#endif

#ifdef SOLUTION_4
int kthLargestValue(vector<vector<int>> &matrix, int k)
{
    vector<int> vals;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i > 0 && j > 0)
            {
                matrix[i][j] ^= matrix[i][j - 1] ^ matrix[i - 1][j] ^ matrix[i - 1][j - 1];
            }
            else if (i > 0)
            {
                matrix[i][j] ^= matrix[i - 1][j];
            }
            else if (j > 0)
            {
                matrix[i][j] ^= matrix[i][j - 1];
            }

            vals.push_back(matrix[i][j]);
        }
    }

    nth_element(vals.begin(), vals.begin() + k - 1, vals.end(), greater<int>());
    return vals[k - 1];
}
#endif

int main()
{
    return 0;
}