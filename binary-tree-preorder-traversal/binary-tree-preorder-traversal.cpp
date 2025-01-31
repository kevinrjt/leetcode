#include "../definitions.h"

#include <stack>
#include <vector>

using namespace std;

#define SOLUTION_3

#ifdef SOLUTION_1
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> vals;
    preorderTraversal(root, vals);
    return vals;
}

void preorderTraversal(TreeNode *root, vector<int> &vals)
{
    if (root != nullptr)
    {
        vals.push_back(root->val);
        preorderTraversal(root->left, vals);
        preorderTraversal(root->right, vals);
    }
}
#endif

#ifdef SOLUTION_2
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> vals;
    stack<TreeNode *> st;
    TreeNode *node = root;
    while (node != nullptr || !st.empty())
    {
        if (node != nullptr)
        {
            vals.push_back(node->val);
            if (node->right != nullptr)
            {
                st.push(node->right);
            }

            node = node->left;
        }
        else
        {
            node = st.top();
            st.pop();
        }
    }

    return vals;
}
#endif

#ifdef SOLUTION_3
// Morris traversal: https://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> vals;
    TreeNode *curr = root;
    while (curr != nullptr)
    {
        if (curr->left != nullptr)
        {
            TreeNode *node = curr->left;
            while (node->right != nullptr && node->right != curr)
            {
                node = node->right;
            }

            if (node->right == nullptr)
            {
                vals.push_back(curr->val);
                node->right = curr;
                curr = curr->left;
            }
            else
            {
                node->right = nullptr;
                curr = curr->right;
            }
        }
        else
        {
            vals.push_back(curr->val);
            curr = curr->right;
        }
    }

    return vals;
}
#endif

int main()
{
    return 0;
}