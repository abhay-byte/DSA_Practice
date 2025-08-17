#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class stack
{

    vector<T> v;

public:
    void push(T val)
    {
        v.push_back(val);
    }

    void pop()
    {
        v.pop_back();
    }

    T size()
    {
        return v.size();
    }

    T top()
    {
        return v.back();
    }

    bool empty()
    {
        return v.empty();
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