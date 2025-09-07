#include "../definitions.h"

#include <iostream>

using namespace std;

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr)
    {
        return head;
    }

    int len = 1;
    ListNode *node = head;
    for (; node->next != nullptr; node = node->next)
    {
        ++len;
    }

    node->next = head;
    k %= len;
    for (int i = (k == 0 ? len : k); i < len; ++i)
    {
        node = node->next;
    }

    head = node->next;
    node->next = nullptr;
    return head;
}

int main()
{
    return 0;
}