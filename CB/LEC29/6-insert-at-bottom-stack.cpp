#include <stack>
#include <iostream>
using namespace std;

// https://cplusplus.com/reference/stack/stack/?kw=stack

void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    cout << endl;
}

// time: O(n) ~ 6n+1
// space: O(n)
void insertAtBottonLinear(stack<int> &s, int val)
{
    stack<int> t;
    while (!s.empty())
    {
        t.push(s.top());
        s.pop();
    }

    s.push(val);

    while (!t.empty())
    {
        s.push(t.top());
        t.pop();
    }
}

// time: O(n) ~ 3n+1
// space: O(n) ~ n function call stack
void insertAtBottonRecursion(stack<int> &s, int val)
{
    // base case

    if (s.empty())
    {
        s.push(val);
        return;
    }

    // recursive case

    int v = s.top();
    s.pop();
    insertAtBottonRecursion(s, val);

    s.push(v);
}

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    print(s);

    int val = 0;

    insertAtBottonRecursion(s, val);

    print(s);

    return 0;
}