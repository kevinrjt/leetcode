#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <iostream>
#include <vector>

#include "definitions.h"

using namespace std;

void printListNode(ListNode *head)
{
    for (ListNode *node = head; node != nullptr; node = node->next)
    {
        cout << node->val << "->";
    }

    cout << "NULL" << endl;
}

ListNode *constructListNode(vector<int> vals)
{
    ListNode dummy;
    ListNode *node = &dummy;
    for (int x : vals)
    {
        node->next = new ListNode(x);
        node = node->next;
    }

    return dummy.next;
}

#endif