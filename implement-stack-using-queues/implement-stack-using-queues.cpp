#include <queue>

using namespace std;

#define SOLUTION_1

#ifdef SOLUTION_1
class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        int len = _queue.size();
        _queue.push(x);
        for (int i = 0; i < len; ++i)
        {
            _queue.push(_queue.front());
            _queue.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int val = _queue.front();
        _queue.pop();
        return val;
    }

    /** Get the top element. */
    int top()
    {
        return _queue.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return _queue.empty();
    }

private:
    queue<int> _queue;
};
#endif

#ifdef SOLUTION_2
class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        _queue.push(x);
        _top = x;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int val = _top;
        int len = _queue.size();
        for (int i = 0; i < len - 1; ++i)
        {
            _top = _queue.front();
            _queue.push(_top);
            _queue.pop();
        }

        _queue.pop();
        return val;
    }

    /** Get the top element. */
    int top()
    {
        return _top;
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return _queue.empty();
    }

private:
    queue<int> _queue;
    int _top;
};
#endif

int main()
{
    return 0;
}