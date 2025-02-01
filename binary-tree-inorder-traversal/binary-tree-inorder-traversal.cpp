#include <stack>
#include <vector>

#include "../definitions.h"

using namespace std;

#define SOLUTION_3

#ifdef SOLUTION_1
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> vals;
    inorderTraversal(root, vals);
    return vals;
}

void inorderTraversal(TreeNode *root, vector<int> &vals)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left, vals);
        vals.push_back(root->val);
        inorderTraversal(root->right, vals);
    }
}
#endif

#ifdef SOLUTION_2
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> vals;
    stack<TreeNode *> st;
    TreeNode *node = root;
    while (node != nullptr || !st.empty())
    {
        if (node != nullptr)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            node = st.top();
            st.pop();
            vals.push_back(node->val);
            node = node->right;
        }
    }

    return vals;
}
#endif

#ifdef SOLUTION_3
vector<int> inorderTraversal(TreeNode *root)
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
                node -> right = curr;
                curr = curr->left;
            }
            else
            {
                vals.push_back(curr->val);
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