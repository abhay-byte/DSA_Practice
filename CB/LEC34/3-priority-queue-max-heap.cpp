#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
    priority_queue<int> m; //by default act as max heap

    m.push(9);
    m.push(7);
    m.push(8);
    m.push(5);
    m.push(4);
    m.push(6);
    m.push(3);
    m.push(2);
    m.push(1);

    cout << m.size() << endl;

    while(!m.empty())
    {
        cout << m.top() << " ";
        m.pop();
    }

    cout << endl;
    cout << m.size() << endl;
}