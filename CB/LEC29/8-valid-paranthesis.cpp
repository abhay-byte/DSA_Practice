#include <stack>
#include <iostream>
using namespace std;

// https://cplusplus.com/reference/stack/stack/?kw=stack

bool isValid(string str)
{
    stack<char> s;

    for (char ch : str)
    {
        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            s.push(ch);
            break;
        case ')':
            if (!s.empty() && s.top() == '(')
                s.pop();
            else
                return false;
            break;
        case ']':
            if (!s.empty() && s.top() == '[')
                s.pop();
            else
                return false;
            break;
        case '}':
            if (!s.empty() && s.top() == '{')
                s.pop();
            else
                return false;
            break;
        }
    }

    return s.empty();
}

int main()
{
    string s = "({[]})";

    cout << isValid(s);

    return 0;
}