#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
bool isAttacked(vector<int> &queens, int next)
{
    for (int i = 0; i < queens.size(); ++i)
    {
        if (queens[i] == next || abs(next - queens[i]) == queens.size() - i)
        {
            return true;
        }
    }

    return false;
}

void addSolution(vector<int> &queens, vector<vector<string>> &solutions)
{
    int n = queens.size();
    vector<string> solution(n, string(n, '.'));
    for (int i = 0; i < n; ++i)
    {
        solution[i][queens[i]] = 'Q';
    }

    solutions.push_back(move(solution));
}

void solveNQueens(int n, vector<int> &queens, vector<vector<string>> &solutions)
{
    if (queens.size() == n)
    {
        addSolution(queens, solutions);
        return;
    }

    for (int col = 0; col < n; ++col)
    {
        if (!isAttacked(queens, col))
        {
            queens.push_back(col);
            solveNQueens(n, queens, solutions);
            queens.pop_back();
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> solutions;
    vector<int> queens;
    solveNQueens(n, queens, solutions);
    return solutions;
}
#endif

#ifdef SOLUTION_2
void solveNQueens(int row, int n, vector<char> &flag, vector<string> &board, vector<vector<string>> &solutions)
{
    if (row == n)
    {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col)
    {
        int diagonal = n + row + col;
        int antidiagonal = 4 * n - 2 + row - col;
        if (!flag[col] && !flag[diagonal] && !flag[antidiagonal])
        {
            board[row][col] = 'Q';
            flag[col] = flag[diagonal] = flag[antidiagonal] = 1;
            solveNQueens(row + 1, n, flag, board, solutions);
            board[row][col] = '.';
            flag[col] = flag[diagonal] = flag[antidiagonal] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    vector<char> flag(5 * n - 2);
    solveNQueens(0, n, flag, board, solutions);
    return solutions;
}
#endif

int main()
{
    return 0;
}