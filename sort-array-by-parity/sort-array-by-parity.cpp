#include <vector>

using namespace std;

#define SOLUTION_2

#ifdef SOLUTION_1
vector<int> sortArrayByParity(vector<int> &A)
{
    int i = 0;
    int j = A.size() - 1;
    while (i < j)
    {
        if (A[i] & 1)
        {
            swap(A[i], A[j--]);
        }
        else
        {
            ++i;
        }
    }

    return A;
}
#endif

#ifdef SOLUTION_2
vector<int> sortArrayByParity(vector<int> &A)
{
    for (int i = 0, j = 0; i < A.size(); ++i)
    {
        if (!(A[i] & 1))
        {
            swap(A[i], A[j++]);
        }
    }

    return A;
}
#endif

int main()
{
    return 0;
}