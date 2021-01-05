#include <vector>

#include "../definitions.h"

using namespace std;

vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    vector<TreeNode *> nodes;
    if (root != nullptr)
    {
        nodes.push_back(root);
    }

    vector<vector<int>> levels;
    while (!nodes.empty())
    {
        vector<TreeNode *> temp(move(nodes));
        vector<int> level;
        for (TreeNode *node : temp)
        {
            level.push_back(node->val);
            if (node->left != nullptr)
            {
                nodes.push_back(node->left);
            }

            if (node->right != nullptr)
            {
                nodes.push_back(node->right);
            }
        }

        levels.push_back(move(level));
    }

    reverse(levels.begin(), levels.end());
    return levels;
}

int main()
{
    return 0;
}