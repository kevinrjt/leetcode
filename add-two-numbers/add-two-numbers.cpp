#include "../definitions.h"

#include <iostream>

using namespace std;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode dummy = ListNode();
    ListNode *node = &dummy;
    int s = 0;
    while (l1 != nullptr || l2 != nullptr || s > 0)
    {
        if (l1 != nullptr)
        {
            s += l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr)
        {
            s += l2->val;
            l2 = l2->next;
        }

        node->next = new ListNode(s % 10);
        node = node->next;
        s /= 10;
    }

    return dummy.next;
}

int main()
{
    return 0;
}