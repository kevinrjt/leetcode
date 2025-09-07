#include "../definitions.h"

#include <vector>

using namespace std;

#define SOLUTION_1

#ifdef SOLUTION_1
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> levels;
    if (!root)
    {
        return levels;
    }

    vector<TreeNode *> nodes{root};
    while (!nodes.empty())
    {
        vector<int> level;
        for (TreeNode *node : vector<TreeNode *>(move(nodes)))
        {
            level.push_back(node->val);
            if (node->left)
            {
                nodes.push_back(node->left);
            }

            if (node->right)
            {
                nodes.push_back(node->right);
            }
        }

        levels.push_back(move(level));
    }

    return levels;
}
#endif

#ifdef SOLUTION_2
// https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/33468/One-of-C%2B%2B-solutions-(preorder)
void dfs(TreeNode *root, int depth, vector<vector<int>> &levels)
{
    if (!root)
    {
        return;
    }

    if (depth == levels.size())
    {
        levels.push_back(vector<int>());
    }

    levels[depth].push_back(root->val);
    dfs(root->left, depth + 1, levels);
    dfs(root->right, depth + 1, levels);
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> levels;
    dfs(root, 0, levels);
    return levels;
}
#endif

int main()
{
    return 0;
}