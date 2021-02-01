#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

string formatString(const string &email)
{
    string formattedEmail;
    int atIndex = email.length() - 1;
    for (; email[atIndex] != '@'; --atIndex)
        ;
    for (int i = 0; i < atIndex && email[i] != '+'; ++i)
    {
        if (email[i] != '.')
        {
            formattedEmail.push_back(email[i]);
        }
    }

    formattedEmail.append(email.substr(atIndex));
    return formattedEmail;
}

int numUniqueEmails(vector<string> &emails)
{
    unordered_set<string> uniqueEmails;
    for (const string &email : emails)
    {
        uniqueEmails.insert(formatString(email));
    }

    return uniqueEmails.size();
}

int main()
{
    return 0;
}