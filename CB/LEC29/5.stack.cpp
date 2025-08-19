#include <stack>
#include <iostream>
using namespace std;

//https://cplusplus.com/reference/stack/stack/?kw=stack

int main()
{
    stack<int> s;

    cout << "size: " << s.size() << endl;
    // cout << "top: " << s.top() << endl;
    cout << "isEmpty ? " << s.empty() << endl;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    while (!s.empty())
    {
        cout << "size: " << s.size() << endl;
        cout << "top: " << s.top() << endl;
        cout << "isEmpty ? " << s.empty() << endl;
        s.pop();
    }
}