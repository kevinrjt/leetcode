#include "../definitions.h"
#include "../utilities.h"

#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define SOLUTION_3

#ifdef SOLUTION_1
void binaryTreePaths(TreeNode *node, const string &prefix, vector<string> &paths)
{
    if (node->left == nullptr && node->right == nullptr)
    {
        paths.push_back(prefix + to_string(node->val));
    }

    if (node->left != nullptr)
    {
        binaryTreePaths(node->left, prefix + to_string(node->val) + "->", paths);
    }

    if (node->right != nullptr)
    {
        binaryTreePaths(node->right, prefix + to_string(node->val) + "->", paths);
    }
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> paths;
    if (root == nullptr)
    {
        return paths;
    }

    binaryTreePaths(root, "", paths);
    return paths;
}
#endif

#ifdef SOLUTION_2
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> paths;
    if (root == nullptr)
    {
        return paths;
    }

    queue<pair<TreeNode *, string>> q;
    q.emplace(root, "");
    while (!q.empty())
    {
        TreeNode *node = q.front().first;
        string prefix = q.front().second;
        q.pop();
        if (node->left == nullptr && node->right == nullptr)
        {
            paths.push_back(prefix + to_string(node->val));
        }

        if (node->left != nullptr)
        {
            q.emplace(node->left, prefix + to_string(node->val) + "->");
        }

        if (node->right != nullptr)
        {
            q.emplace(node->right, prefix + to_string(node->val) + "->");
        }
    }

    return paths;
}
#endif

#ifdef SOLUTION_3
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> paths;
    if (root == nullptr)
    {
        return paths;
    }

    stack<pair<TreeNode *, string>> q;
    q.emplace(root, "");
    while (!q.empty())
    {
        TreeNode *node = q.top().first;
        string prefix = q.top().second;
        q.pop();
        if (node->left == nullptr && node->right == nullptr)
        {
            paths.push_back(prefix + to_string(node->val));
        }

        if (node->left != nullptr)
        {
            q.emplace(node->left, prefix + to_string(node->val) + "->");
        }

        if (node->right != nullptr)
        {
            q.emplace(node->right, prefix + to_string(node->val) + "->");
        }
    }

    return paths;
}
#endif

int main()
{
    TreeNode root;
    printVector(binaryTreePaths(&root));
    return 0;
}