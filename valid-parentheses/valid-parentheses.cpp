#include <stack>
#include <string>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
bool isMatch(char c1, char c2)
{
    return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}');
}

bool isValid(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            if (st.empty() || !isMatch(st.top(), c))
            {
                return false;
            }

            st.pop();
        }
    }

    return st.empty();
}
#endif

#ifdef SOLUTION_2
bool isValid(string s)
{
    stack<char> st;
    for (char c : s)
    {
        switch (c)
        {
        case '(':
            st.push(')');
            break;
        case '[':
            st.push(']');
            break;
        case '{':
            st.push('}');
            break;
        default:
            if (st.empty() || st.top() != c)
            {
                return false;
            }

            st.pop();
        }
    }

    return st.empty();
}
#endif

int main()
{
    return 0;
}