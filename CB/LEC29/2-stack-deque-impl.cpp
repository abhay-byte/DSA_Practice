#include <deque>
#include <iostream>
using namespace std;

template <typename T>
class stack
{

    deque<T> d;

public:
    void push(T val)
    {
        d.push_back(val);
    }

    void pop()
    {
        d.pop_back();
    }

    T size()
    {
        return d.size();
    }

    T top()
    {
        return d.back();
    }

    bool empty()
    {
        return d.empty();
    }
};

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