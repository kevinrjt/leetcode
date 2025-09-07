#include "../definitions.h"

#include <iostream>

using namespace std;

ListNode *swapPairs(ListNode *head)
{
    ListNode dummy = ListNode(0, head);
    ListNode *node = &dummy;
    while (node->next != nullptr && node->next->next != nullptr)
    {
        ListNode *temp = node->next;
        node->next = temp->next;
        temp->next = node->next->next;
        node->next->next = temp;

        node = temp;
    }

    return dummy.next;
}

int main()
{
    return 0;
}