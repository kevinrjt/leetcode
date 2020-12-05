#include <iostream>
#include <unordered_map>

#include "../definitions.h"

typedef RandomListNode Node;

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> table;
    Node dummy(0);
    Node *newNode = &dummy;
    Node *node = head;
    while (node != nullptr)
    {
        newNode->next = new Node(node->val);
        newNode = newNode->next;
        table[node] = newNode;
        node = node->next;
    }

    node = head;
    newNode = dummy.next;
    while (node != nullptr)
    {
        newNode->random = table[node->random];
        newNode = newNode->next;
        node = node->next;
    }

    return dummy.next;
}
#endif

#ifdef SOLUTION_2
Node *copyRandomList(Node *head)
{
    Node *node = head;
    while (node != nullptr)
    {
        Node *newNode = new Node(node->val);
        newNode->next = node->next;
        node->next = newNode;
        node = newNode->next;
    }

    node = head;
    while (node != nullptr)
    {
        node->next->random = node->random != nullptr ? node->random->next : nullptr;
        node = node->next->next;
    }

    Node dummy(0);
    Node *newNode = &dummy;
    node = head;
    while (node != nullptr)
    {
        newNode->next = node->next;
        newNode = newNode->next;
        node->next = newNode->next;
        node = node->next;
    }

    return dummy.next;
}
#endif

#ifdef SOLUTION_3
Node *copyRandomList(Node *head)
{
    Node *node = head;
    while (node != nullptr)
    {
        Node *newNode = new Node(node->val);
        newNode->next = node->random;
        node->random = newNode;
        node = node->next;
    }

    node = head;
    while (node != nullptr)
    {
        Node *newNode = node->random;
        newNode->random = newNode->next != nullptr ? newNode->next->random : nullptr;
        node = node->next;
    }

    Node dummy(0);
    Node *newNode = &dummy;
    node = head;
    while (node != nullptr)
    {
        newNode->next = node->random;
        newNode = newNode->next;
        node->random = newNode->next;
        node = node->next;
    }

    newNode->next = nullptr;
    return dummy.next;
}
#endif

int main()
{
    Node node(0);
    node.random = &node;
    cout << &node << endl;
    cout << copyRandomList(&node) << endl;
    return 0;
}