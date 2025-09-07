#include "../definitions.h"

#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define SOLUTION_3

#ifdef SOLUTION_1
class NestedIterator
{
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        for (auto &nestedInt : nestedList)
        {
            iterate(nestedInt);
        }
    }

    int next()
    {
        return _vals[_index++];
    }

    bool hasNext()
    {
        return _index < _vals.size();
    }

private:
    void iterate(const NestedInteger &nestedInt)
    {
        if (nestedInt.isInteger())
        {
            _vals.push_back(nestedInt.getInteger());
        }
        else
        {
            for (auto &child : nestedInt.getList())
            {
                iterate(child);
            }
        }
    }

    vector<int> _vals;
    int _index = 0;
};
#endif

#ifdef SOLUTION_2
class NestedIterator
{
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        _stack.emplace(&nestedList, -1);
        advance();
    }

    int next()
    {
        auto p = _stack.top();
        int val = p.first->at(p.second).getInteger();
        advance();
        return val;
    }

    bool hasNext()
    {
        return !_stack.empty();
    }

private:
    void advance()
    {
        while (!_stack.empty())
        {
            ++_stack.top().second;
            auto p = _stack.top();
            if (p.second < p.first->size())
            {
                auto &nestedInt = p.first->at(p.second);
                if (nestedInt.isInteger())
                {
                    break;
                }

                _stack.emplace(&(nestedInt.getList()), -1);
            }
            else
            {
                _stack.pop();
            }
        }
    }

    stack<pair<const vector<NestedInteger> *, int>> _stack;
};
#endif

#ifdef SOLUTION_3
class NestedIterator
{
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        push(nestedList);
    }

    int next()
    {
        hasNext();
        int val = _stack.top()->getInteger();
        _stack.pop();
        return val;
    }

    bool hasNext()
    {
        while (!_stack.empty() && !_stack.top()->isInteger())
        {
            auto nestedInt = _stack.top();
            _stack.pop();
            push(nestedInt->getList());
        }

        return !_stack.empty();
    }

private:
    void push(const vector<NestedInteger> &nestedList)
    {
        for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it)
        {
            _stack.push(&(*it));
        }
    }

    stack<const NestedInteger *> _stack;
};
#endif

int main()
{
    vector<NestedInteger> nestedList{vector<NestedInteger>{1, 2}, 3, vector<NestedInteger>{vector<NestedInteger>{vector<NestedInteger>{4, 5}, 6}, 7, vector<NestedInteger>{8, 9}}};
    NestedIterator i(nestedList);
    while (i.hasNext())
    {
        cout << i.next() << " ";
    }

    cout << endl;
    return 0;
}