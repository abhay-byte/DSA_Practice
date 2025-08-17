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
void reverseStackLinear(stack<int> &s)
{

}

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

// time: O(n^2)  ~ t(n) = t(n-1) + n.c 
// space: O(n) ~ due to function call stack
void reverseStackRecursion(stack<int> &s)
{
    // base case

    if (s.empty())
    {
        return;
    }

    // recursive case

    int v = s.top();
    s.pop();
    reverseStackRecursion(s);

    insertAtBottonRecursion(s,v);
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

    reverseStackRecursion(s);

    print(s);

    return 0;
}