#include "../definitions.h"

#include <iostream>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
void deleteNode(ListNode *node)
{
    ListNode *temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    delete temp;
}
#endif

#ifdef SOLUTION_2
void deleteNode(ListNode *node)
{
    ListNode *temp = node->next;
    *node = *temp;
    delete temp;
}
#endif

int main()
{
    return 0;
}