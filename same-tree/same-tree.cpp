#include <stack>

#include "../definitions.h"

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr || q == nullptr)
    {
        return p == q;
    }

    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
#endif

#ifdef SOLUTION_2
bool isSameTree(TreeNode *p, TreeNode *q)
{
    stack<TreeNode *> st;
    st.push(p);
    st.push(q);
    while (!st.empty())
    {
        q = st.top();
        st.pop();
        p = st.top();
        st.pop();
        if (p == nullptr && q == nullptr)
        {
            continue;
        }
        else if (p == nullptr || q == nullptr || p->val != q->val)
        {
            return false;
        }

        st.push(p->right);
        st.push(q->right);
        st.push(p->left);
        st.push(q->left);
    }

    return true;
}
#endif

int main()
{
    return 0;
}