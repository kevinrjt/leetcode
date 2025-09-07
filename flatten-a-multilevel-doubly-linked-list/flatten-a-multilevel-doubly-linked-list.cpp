#include "../definitions.h"

#include <stack>

using namespace std;

typedef MultilevelDoublyLinkedListNode Node;

#define SOLUTION_5

#ifdef SOLUTION_1
Node *flattenAndReturnTail(Node *head)
{
    if (head == nullptr)
    {
        return head;
    }

    Node *tail = flattenAndReturnTail(head->next);
    Node *childTail = flattenAndReturnTail(head->child);
    if (childTail != nullptr)
    {
        if (head->next != nullptr)
        {
            head->next->prev = childTail;
            childTail->next = head->next;
        }

        head->next = head->child;
        head->child->prev = head;
        head->child = nullptr;
    }

    return tail != nullptr ? tail : (childTail != nullptr ? childTail : head);
}

Node *flatten(Node *head)
{
    flattenAndReturnTail(head);
    return head;
}
#endif

#ifdef SOLUTION_2
// Neat recursive solution: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/discuss/295912
Node *flatten(Node *head, Node *rest)
{
    if (head == nullptr)
    {
        return rest;
    }

    head->next = flatten(head->child, flatten(head->next, rest));
    if (head->next != nullptr)
    {
        head->next->prev = head;
    }

    head->child = nullptr;
    return head;
}

Node *flatten(Node *head)
{
    return flatten(head, nullptr);
}
#endif

#ifdef SOLUTION_3
Node *flatten(Node *head)
{
    if (head == nullptr)
    {
        return head;
    }

    Node dummy;
    Node *prev = &dummy;
    stack<Node *> st;
    st.push(head);
    while (!st.empty())
    {
        Node *node = st.top();
        st.pop();
        if (node->next != nullptr)
        {
            st.push(node->next);
        }

        if (node->child != nullptr)
        {
            st.push(node->child);
        }

        prev->next = node;
        node->prev = prev;
        node->child = nullptr;
        prev = node;
    }

    head->prev = nullptr;
    return head;
}
#endif

#ifdef SOLUTION_4
Node *flatten(Node *head)
{
    Node *node = head;
    stack<Node *> st;
    while (node != nullptr)
    {
        if (node->child != nullptr)
        {
            if (node->next != nullptr)
            {
                st.push(node->next);
            }

            node->next = node->child;
            node->next->prev = node;
            node->child = nullptr;
        }
        else
        {
            if (node->next == nullptr && !st.empty())
            {
                node->next = st.top();
                node->next->prev = node;
                st.pop();
            }
        }

        node = node->next;
    }

    return head;
}
#endif

#ifdef SOLUTION_5
Node *flatten(Node *head)
{
    Node *node = head;
    while (node != nullptr)
    {
        if (node->child != nullptr)
        {
            Node *tail = node->child;
            while (tail->next != nullptr)
            {
                tail = tail->next;
            }

            tail->next = node->next;
            if (tail->next != nullptr)
            {
                tail->next->prev = tail;
            }

            node->next = node->child;
            node->next->prev = node;
            node->child = nullptr;
        }

        node = node->next;
    }

    return head;
}
#endif

int main()
{
    return 0;
}