#include <string>
#include <vector>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
string restoreString(string s, vector<int> &indices)
{
    int len = s.length();
    string t(len, 0);
    for (int i = 0; i < len; ++i)
    {
        t[indices[i]] = s[i];
    }

    return t;
}
#endif

#ifdef SOLUTION_2
// Cyclic Sort
string restoreString(string s, vector<int> &indices)
{
    int len = s.length();
    for (int i = 0; i < len; ++i)
    {
        while (indices[i] != i)
        {
            swap(s[i], s[indices[i]]);
            swap(indices[i], indices[indices[i]]);
        }
    }

    return s;
}
#endif

#ifdef SOLUTION_3
// Cyclic Sort, less array writes
string restoreString(string s, vector<int> &indices)
{
    int len = s.length();
    for (int i = 0; i < len; ++i)
    {
        int next = indices[i];
        char nextChar = s[i];
        while (next != i)
        {
            int temp = indices[next];
            char tempChar = s[next];

            indices[next] = next;
            s[next] = nextChar;

            next = temp;
            nextChar = tempChar;
        }

        // indices[i] = next;
        s[i] = nextChar;
    }

    return s;
}
#endif

int main()
{
    return 0;
}