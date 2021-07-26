#include "../definitions.h"

#define SOLUTION_2

#ifdef SOLUTION_1
TreeNode *searchBST(TreeNode *root, int val)
{
    return (root == nullptr || root->val == val) ? root : (root->val > val ? searchBST(root->left, val) : searchBST(root->right, val));
}
#endif

#ifdef SOLUTION_2
TreeNode *searchBST(TreeNode *root, int val)
{
    while (root != nullptr && root->val != val)
    {
        root = root->val > val ? root->left : root->right;
    }

    return root;
}
#endif

int main()
{
    return 0;
}