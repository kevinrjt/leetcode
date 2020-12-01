#include <iostream>

#include "../definitions.h"
#include "../utilities.h"

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

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

bool isPalindrome(ListNode *head)
{
    ListNode *middle = middleNode(head);
    ListNode *left = head;
    ListNode *right = reverseList(middle);
    while (right != nullptr)
    {
        if (left->val != right->val)
        {
            return false;
        }

        left = left->next;
        right = right->next;
    }

    return true;
}
#endif

#ifdef SOLUTION_2
bool isPalindrome(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *reversedHead = nullptr;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;

        ListNode *temp = slow->next;
        slow->next = reversedHead;
        reversedHead = slow;
        slow = temp;
    }

    ListNode *left = reversedHead;
    ListNode *right = fast != nullptr ? slow->next : slow;
    bool result = true;
    while (right != nullptr)
    {
        result = result && left->val == right->val;

        ListNode *temp = left->next;
        left->next = slow;
        slow = left;

        left = temp;
        right = right->next;
    }

    return result;
}
#endif

int main()
{
    ListNode *head = constructListNode({1, 2, 3, 2, 1});
    printListNode(head);
    cout << (isPalindrome(head) ? "Yes" : "No") << endl;
    printListNode(head);

    head = constructListNode({1, 2, 3, 3, 2, 1});
    printListNode(head);
    cout << (isPalindrome(head) ? "Yes" : "No") << endl;
    printListNode(head);

    return 0;
}