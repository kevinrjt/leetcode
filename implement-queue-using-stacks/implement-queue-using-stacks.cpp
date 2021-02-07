#include <stack>

using namespace std;

#define SOLUTION_1

#ifdef SOLUTION_1
class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        _inStack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int val = peek();
        _outStack.pop();
        return val;
    }

    /** Get the front element. */
    int peek()
    {
        if (_outStack.empty())
        {
            while (!_inStack.empty())
            {
                _outStack.push(_inStack.top());
                _inStack.pop();
            }
        }

        return _outStack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return _inStack.empty() && _outStack.empty();
    }

private:
    stack<int> _inStack;
    stack<int> _outStack;
};
#endif

#ifdef SOLUTION_2
class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        if (_stack.empty())
        {
            _stack.push(x);
            return;
        }

        int val = _stack.top();
        _stack.pop();
        push(x);
        _stack.push(val);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int val = _stack.top();
        _stack.pop();
        return val;
    }

    /** Get the front element. */
    int peek()
    {
        return _stack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return _stack.empty();
    }

private:
    stack<int> _stack;
};
#endif

int main()
{
    return 0;
}