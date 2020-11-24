#include <iostream>

#include "definitions.h"

using namespace std;

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *node = head;
    while (node != nullptr && node->next != nullptr)
    {
        if (node->val == node->next->val)
        {
            node->next = node->next->next;
        }
        else
        {
            node = node->next;
        }
    }

    return head;
}

int main()
{
    return 0;
}