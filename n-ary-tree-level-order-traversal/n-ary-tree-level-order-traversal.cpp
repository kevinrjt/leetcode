#include <queue>
#include <vector>

#include "../definitions.h"

typedef NaryTreeNode Node;

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
vector<vector<int>> levelOrder(Node *root)
{
    queue<Node *> nodes;
    if (root != nullptr)
    {
        nodes.push(root);
    }

    vector<vector<int>> levels;
    while (!nodes.empty())
    {
        int n = nodes.size();
        vector<int> level;
        for (int i = 0; i < n; ++i)
        {
            Node *node = nodes.front();
            nodes.pop();
            level.push_back(node->val);
            for (Node *child : node->children)
            {
                nodes.push(child);
            }
        }

        levels.push_back(move(level));
    }

    return levels;
}
#endif

#ifdef SOLUTION_2
void levelOrder(Node *root, int depth, vector<vector<int>> &levels)
{
    if (depth == levels.size())
    {
        levels.push_back(vector<int>());
    }

    levels[depth].push_back(root->val);
    for (Node *child : root->children)
    {
        levelOrder(child, depth + 1, levels);
    }
}

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> levels;
    if (root == nullptr)
    {
        return levels;
    }

    levelOrder(root, 0, levels);
    return levels;
}
#endif

int main()
{
    return 0;
}