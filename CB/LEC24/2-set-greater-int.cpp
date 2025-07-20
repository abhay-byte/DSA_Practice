#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int, greater<int>> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    for (int i : s)
    {
        cout << i << endl;
    }

    s.erase(5);
    auto it = s.begin();
    it++;
    s.erase(it);

    for (int i : s)
    {
        cout << i << endl;
    }

    cout << s.size() << endl;

    if (s.find(2) != s.end())
    {
        cout << "present";
    }
    else
    {
        cout << "absent";
    }

    if (s.count(4))
    {
        cout << "present";
    }
    else
    {
        cout << "absent";
    }

    for (auto it = s.begin(), end = s.end(); it != end; it++)
    {
        cout << *it;
    }
}