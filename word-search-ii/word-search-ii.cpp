#include <iostream>
#include <string>
#include <vector>

#include "../utilities.h"

using namespace std;

#define SOLUTION_1

#ifdef SOLUTION_1
struct TrieNode
{
    string *word = nullptr;
    int count = 0;
    TrieNode *children[26] = {nullptr};
};

TrieNode *buildTrie(vector<string> &words)
{
    TrieNode *root = new TrieNode();
    for (auto &word : words)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children[c - 'a'] == nullptr)
            {
                node->children[c - 'a'] = new TrieNode();
            }

            node = node->children[c - 'a'];
            node->count++;
        }

        node->word = &word;
    }

    return root;
}

void deleteTrie(TrieNode *root)
{
    if (root != nullptr)
    {
        for (TrieNode *child : root->children)
        {
            deleteTrie(child);
        }

        delete root;
    }
}

int search(vector<vector<char>> &board, int row, int col, TrieNode *node, vector<string> &result)
{
    int foundCount = 0;
    if (node->word != nullptr)
    {
        result.push_back(*(node->word));
        node->word = nullptr;
        ++foundCount;
    }

    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || !board[row][col])
    {
        node->count -= foundCount;
        return foundCount;
    }

    char c = board[row][col];
    TrieNode *child = node->children[c - 'a'];
    if (child != nullptr && child->count > 0)
    {
        board[row][col] = 0;
        foundCount += search(board, row, col - 1, child, result);
        foundCount += search(board, row, col + 1, child, result);
        foundCount += search(board, row - 1, col, child, result);
        foundCount += search(board, row + 1, col, child, result);
        board[row][col] = c;
    }

    node->count -= foundCount;
    return foundCount;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    TrieNode *root = buildTrie(words);
    vector<string> result;
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            search(board, i, j, root, result);
        }
    }

    deleteTrie(root);
    return result;
}
#endif

#ifdef SOLUTION_2
bool exist(vector<vector<char>> &board, const string &word, int row, int col, int charIdx)
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
    bool result = exist(board, word, row, col - 1, charIdx + 1) ||
                  exist(board, word, row, col + 1, charIdx + 1) ||
                  exist(board, word, row - 1, col, charIdx + 1) ||
                  exist(board, word, row + 1, col, charIdx + 1);
    board[row][col] = word[charIdx];
    return result;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    vector<string> result;
    for (auto &word : words)
    {
        bool found = false;
        for (int i = 0; i < board.size() && !found; ++i)
        {
            for (int j = 0; j < board[0].size() && !found; ++j)
            {
                if (exist(board, word, i, j, 0))
                {
                    result.push_back(word);
                    found = true;
                }
            }
        }
    }

    return result;
}
#endif

int main()
{
    vector<vector<char>> board{{'o', 'a', 'b', 'n'}, {'o', 't', 'a', 'e'}, {'a', 'h', 'k', 'r'}, {'a', 'f', 'l', 'v'}};
    vector<string> words{"oa", "oaa"};
    printVector(findWords(board, words));
    return 0;
}