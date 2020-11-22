#include <iostream>
#include <queue>

#include "definitions.h"

using namespace std;

#define SOLUTION_1

#ifdef SOLUTION_1
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode dummy = ListNode();
    ListNode *node = &dummy;
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val <= l2->val)
        {
            node->next = l1;
            l1 = l1->next;
        }
        else
        {
            node->next = l2;
            l2 = l2->next;
        }

        node = node->next;
    }

    node->next = l1 != nullptr ? l1 : l2;
    return dummy.next;
}

ListNode *mergeKLists(vector<ListNode *> &lists, int start, int end)
{
    if (start == end)
    {
        return lists[start];
    }

    int mid = start + (end - start) / 2;
    return mergeTwoLists(mergeKLists(lists, start, mid), mergeKLists(lists, mid + 1, end));
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    return lists.empty() ? nullptr : mergeKLists(lists, 0, lists.size() - 1);
}
#endif

#ifdef SOLUTION_2
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode dummy = ListNode();
    ListNode *node = &dummy;
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val <= l2->val)
        {
            node->next = l1;
            l1 = l1->next;
        }
        else
        {
            node->next = l2;
            l2 = l2->next;
        }

        node = node->next;
    }

    node->next = l1 != nullptr ? l1 : l2;
    return dummy.next;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    int len = lists.size();
    for (int step = 1; step < len; step *= 2)
    {
        for (int i = 0; i < len - step; i += 2 * step)
        {
            lists[i] = mergeTwoLists(lists[i], lists[i + step]);
        }
    }

    return len > 0 ? lists[0] : nullptr;
}
#endif

#ifdef SOLUTION_3
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    auto cmp = [](ListNode *left, ListNode *right) { return left->val >= right->val; };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
    for (ListNode *list : lists)
    {
        if (list != nullptr)
        {
            pq.push(list);
        }
    }

    ListNode dummy = ListNode();
    ListNode *node = &dummy;
    while (!pq.empty())
    {
        node->next = pq.top();
        pq.pop();
        node = node->next;
        if (node->next != nullptr)
        {
            pq.push(node->next);
        }
    }

    return dummy.next;
}
#endif

int main()
{
    return 0;
}