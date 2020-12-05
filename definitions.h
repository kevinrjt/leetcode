#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

#include <vector>

using namespace std;

// Definition for a singly-linked list node.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a singly-linked list node with random pointer.
struct RandomListNode
{
    int val;
    RandomListNode *next;
    RandomListNode *random;

    RandomListNode(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Definition for a graph node.
class GraphNode
{
public:
    int val;
    vector<GraphNode *> neighbors;

    GraphNode()
    {
        val = 0;
        neighbors = vector<GraphNode *>();
    }

    GraphNode(int _val)
    {
        val = _val;
        neighbors = vector<GraphNode *>();
    }

    GraphNode(int _val, vector<GraphNode *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

#endif