#include <iostream>

#include "../definitions.h"

using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *nodeA = headA;
    ListNode *nodeB = headB;
    while (nodeA != nodeB)
    {
        nodeA = nodeA != nullptr ? nodeA->next : headB;
        nodeB = nodeB != nullptr ? nodeB->next : headA;
    }

    return nodeA;
}

int main()
{
    return 0;
}