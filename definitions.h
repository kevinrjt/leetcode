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

// Definition for a multilevel doubly-linked list node.
struct MultilevelDoublyLinkedListNode
{
    int val;
    MultilevelDoublyLinkedListNode *prev;
    MultilevelDoublyLinkedListNode *next;
    MultilevelDoublyLinkedListNode *child;
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

// Definition for a N-ary tree node.
class NaryTreeNode
{
public:
    int val;
    vector<NaryTreeNode *> children;

    NaryTreeNode() {}

    NaryTreeNode(int _val)
    {
        val = _val;
    }

    NaryTreeNode(int _val, vector<NaryTreeNode *> _children)
    {
        val = _val;
        children = _children;
    }
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

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
    NestedInteger() : _isInt(false) {}

    NestedInteger(int val) : _isInt(true), _val(val) {}

    NestedInteger(vector<NestedInteger> &list) : _isInt(false), _list(list) {}

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const
    {
        return _isInt;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const
    {
        return _val;
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const
    {
        return _list;
    }

private:
    bool _isInt;
    int _val;
    vector<NestedInteger> _list;
};

#endif