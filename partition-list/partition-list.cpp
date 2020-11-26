#include <iostream>

#include "../definitions.h"

using namespace std;

ListNode *partition(ListNode *head, int x)
{
    ListNode dummy1, dummy2;
    ListNode *tail1 = &dummy1, *tail2 = &dummy2;
    for (ListNode *node = head; node != nullptr; node = node->next)
    {
        if (node->val < x)
        {
            tail1->next = node;
            tail1 = node;
        }
        else
        {
            tail2->next = node;
            tail2 = node;
        }
    }

    tail1->next = dummy2.next;
    tail2->next = nullptr;
    return dummy1.next;
}

int main()
{
    return 0;
}