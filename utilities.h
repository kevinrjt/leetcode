#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "definitions.h"

#include <iostream>
#include <vector>

using namespace std;

void printListNode(ListNode *head)
{
    for (ListNode *node = head; node != nullptr; node = node->next)
    {
        cout << node->val << "->";
    }

    cout << "null" << endl;
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

template <typename T>
void printVector(vector<T> v)
{
    int len = v.size();
    for (int i = 0; i < len - 1; ++i)
    {
        cout << v[i] << ",";
    }

    cout << v[len - 1] << endl;
}

#endif