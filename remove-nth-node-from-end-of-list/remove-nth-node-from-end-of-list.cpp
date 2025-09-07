#include "../definitions.h"

#include <iostream>

using namespace std;

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode dummy = ListNode(0, head);
    ListNode *slow = &dummy;
    ListNode *fast = slow;
    for (int i = 0; i < n; ++i)
    {
        fast = fast->next;
    }

    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode *nthFromEnd = slow->next;
    slow->next = nthFromEnd->next;
    delete nthFromEnd;
    return dummy.next;
}

int main()
{
    return 0;
}