#include <string>
#include <vector>

using namespace std;

bool search(vector<vector<char>> &board, const string &word, int row, int col, int charIdx)
{
    if (charIdx == word.length())
    {
        return true;
    }

    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[charIdx])
    {
        return false;
    }

    board[row][col] = 0;
    bool result = search(board, word, row, col - 1, charIdx + 1) ||
                  search(board, word, row, col + 1, charIdx + 1) ||
                  search(board, word, row - 1, col, charIdx + 1) ||
                  search(board, word, row + 1, col, charIdx + 1);
    board[row][col] = word[charIdx];
    return result;
}

bool exist(vector<vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            if (search(board, word, i, j, 0))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    return 0;
}