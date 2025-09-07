#include "../definitions.h"

#include <iostream>

using namespace std;

ListNode *removeElements(ListNode *head, int val)
{
    ListNode **pNode = &head;
    while (*pNode != nullptr)
    {
        if ((*pNode)->val == val)
        {
            ListNode *temp = *pNode;
            *pNode = (*pNode)->next;
            delete temp;
        }
        else
        {
            pNode = &((*pNode)->next);
        }
    }

    return head;
}

int main()
{
    return 0;
}