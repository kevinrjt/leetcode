#include "../definitions.h"

#include <iostream>

using namespace std;

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode **pNode = &head;
    while (*pNode != nullptr)
    {
        ListNode *node = *pNode;
        if (node->next != nullptr && node->val == node->next->val)
        {
            int val = node->val;
            while (node != nullptr && node->val == val)
            {
                ListNode *temp = node;
                node = node->next;
                delete temp;
            }

            *pNode = node;
        }
        else
        {
            pNode = &(node->next);
        }
    }

    return head;
}

int main()
{
    return 0;
}