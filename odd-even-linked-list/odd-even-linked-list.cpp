#include "../definitions.h"

#include <iostream>

using namespace std;

ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = even;
    while (even != nullptr && even->next != nullptr)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return head;
}

int main()
{
    return 0;
}