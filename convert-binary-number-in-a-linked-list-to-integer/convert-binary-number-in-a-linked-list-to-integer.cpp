#include <iostream>

#include "../definitions.h"

using namespace std;

int getDecimalValue(ListNode *head)
{
    int val = 0;
    for (ListNode *node = head; node != nullptr; node = node->next)
    {
        val = (val << 1) | (node->val);
    }

    return val;
}

int main()
{
    return 0;
}