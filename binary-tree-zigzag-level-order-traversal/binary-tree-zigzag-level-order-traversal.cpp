#include "../definitions.h"

#include <vector>

using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<TreeNode *> nodes;
    if (root != nullptr)
    {
        nodes.push_back(root);
    }

    vector<vector<int>> levels;
    bool shouldReverse = false;
    while (!nodes.empty())
    {
        int len = nodes.size();
        vector<TreeNode *> temp(move(nodes));
        vector<int> level(len);
        for (int i = 0; i < len; ++i)
        {
            level[shouldReverse ? len - 1 - i : i] = temp[i]->val;
            if (temp[i]->left != nullptr)
            {
                nodes.push_back(temp[i]->left);
            }

            if (temp[i]->right != nullptr)
            {
                nodes.push_back(temp[i]->right);
            }
        }

        shouldReverse = !shouldReverse;
        levels.push_back(move(level));
    }

    return levels;
}

int main()
{
    return 0;
}