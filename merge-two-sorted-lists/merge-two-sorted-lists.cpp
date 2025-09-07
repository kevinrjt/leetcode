#include "../definitions.h"

#include <iostream>

using namespace std;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode dummy = ListNode();
    ListNode *node = &dummy;
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val <= l2->val)
        {
            node->next = l1;
            l1 = l1->next;
        }
        else
        {
            node->next = l2;
            l2 = l2->next;
        }

        node = node->next;
    }

    node->next = l1 != nullptr ? l1 : l2;
    return dummy.next;
}

int main()
{
    return 0;
}