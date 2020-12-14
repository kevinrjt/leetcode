#include <sstream>
#include <string>

using namespace std;

string interpret(string command)
{
    stringstream result;
    for (int i = 0; i < command.length();)
    {
        if (command[i] == '(')
        {
            if (command[i + 1] == ')')
            {
                result << 'o';
                i += 2;
            }
            else
            {
                result << "al";
                i += 4;
            }
        }
        else
        {
            result << 'G';
            i += 1;
        }
    }

    return result.str();
}

int main()
{
    return 0;
}