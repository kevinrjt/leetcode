#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

#define SOLUTION_5

#ifdef SOLUTION_1
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        int minVal = x;
        if (!_nodes.empty())
        {
            minVal = min(minVal, _nodes.top().second);
        }

        _nodes.emplace(x, minVal);
    }

    void pop()
    {
        _nodes.pop();
    }

    int top()
    {
        return _nodes.top().first;
    }

    int getMin()
    {
        return _nodes.top().second;
    }

private:
    stack<pair<int, int>> _nodes;
};
#endif

#ifdef SOLUTION_2
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        _vals.push(x);
        if (_mins.empty() || x <= _mins.top())
        {
            _mins.push(x);
        }
    }

    void pop()
    {
        if (_vals.top() == _mins.top())
        {
            _mins.pop();
        }

        _vals.pop();
    }

    int top()
    {
        return _vals.top();
    }

    int getMin()
    {
        return _mins.top();
    }

private:
    stack<int> _vals;
    stack<int> _mins;
};
#endif

#ifdef SOLUTION_3
// https://leetcode.com/problems/min-stack/discuss/49014/Java-accepted-solution-using-one-stack
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        if (x <= _min)
        {
            _vals.push(_min);
            _min = x;
        }

        _vals.push(x);
    }

    void pop()
    {
        if (_vals.top() == _min)
        {
            _vals.pop();
            _min = _vals.top();
        }

        _vals.pop();
    }

    int top()
    {
        return _vals.top();
    }

    int getMin()
    {
        return _min;
    }

private:
    int _min = INT_MAX;
    stack<int> _vals;
};
#endif

#ifdef SOLUTION_4
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        _gaps.push(x - _min);
        if (x < _min)
        {
            _min = x;
        }
    }

    void pop()
    {
        long long gap = _gaps.top();
        _gaps.pop();
        if (gap < 0)
        {
            _min -= gap;
        }
    }

    int top()
    {
        long long gap = _gaps.top();
        return int(gap < 0 ? _min : _min + gap);
    }

    int getMin()
    {
        return int(_min);
    }

private:
    long long _min = INT_MAX;
    stack<long long> _gaps;
};
#endif

#ifdef SOLUTION_5
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    ~MinStack()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(int x)
    {
        head = new Node(x, head ? min(x, head->min) : x, head);
    }

    void pop()
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    int top()
    {
        return head->val;
    }

    int getMin()
    {
        return head->min;
    }

private:
    struct Node
    {
        int val;
        int min;
        Node *next;
        Node(int _val, int _min, Node *_next) : val(_val), min(_min), next(_next) {}
    };

    Node *head = nullptr;
};
#endif

int main()
{
    MinStack minStack;
    minStack.push(1);
    minStack.push(2);
    minStack.push(0);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.getMin() << endl;
    minStack.pop();
    return 0;
}