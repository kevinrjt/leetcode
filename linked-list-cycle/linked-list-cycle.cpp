#include <iostream>

#include "definitions.h"

using namespace std;

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    return 0;
}