#include <iostream>

#include "../definitions.h"

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *reversedList = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return reversedList;
}
#endif

#ifdef SOLUTION_2
ListNode *reverseList(ListNode *head)
{
    ListNode *node = head;
    head = nullptr;
    while (node != nullptr)
    {
        ListNode *temp = node->next;
        node->next = head;
        head = node;
        node = temp;
    }

    return head;
}
#endif

int main()
{
    return 0;
}