#include <iostream>

#include "definitions.h"

using namespace std;

ListNode *reverseBetween(ListNode *head, int m, int n)
{
    ListNode dummy(0, head);
    ListNode *preHead = &dummy;
    for (int i = 1; i < m; ++i)
    {
        preHead = preHead->next;
    }

    ListNode *node = preHead->next;
    for (int i = m; i < n; ++i)
    {
        ListNode *tempNext = node->next;
        node->next = tempNext->next;
        tempNext->next = preHead->next;
        preHead->next = tempNext;
    }

    return dummy.next;
}

int main()
{
    return 0;
}