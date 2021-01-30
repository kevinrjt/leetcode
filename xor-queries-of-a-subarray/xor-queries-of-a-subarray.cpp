#include <vector>

using namespace std;

vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    vector<int> prefix(arr.size() + 1);
    for (int i = 0; i < arr.size(); ++i)
    {
        prefix[i + 1] = prefix[i] ^ arr[i];
    }

    vector<int> result(queries.size());
    for (int i = 0; i < queries.size(); ++i)
    {
        result[i] = prefix[queries[i][0]] ^ prefix[queries[i][1] + 1];
    }

    return result;
}

int main()
{
    return 0;
}