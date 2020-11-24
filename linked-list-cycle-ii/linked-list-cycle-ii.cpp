#include <iostream>

#include "../definitions.h"

using namespace std;

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            while (slow != head)
            {
                slow = slow->next;
                head = head->next;
            }

            return slow;
        }
    }

    return nullptr;
}

int main()
{
    return 0;
}