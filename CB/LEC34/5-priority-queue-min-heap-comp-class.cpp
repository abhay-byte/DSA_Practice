#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class customer
{

public:
    string name;
    int age;

    customer(string name, int age)
    {
        this->age = age;
        this->name = name;
    }
};

class customerAgeComp
{
public:
    // return true if you want a to be order before b
    // bool operator()(customer a, customer b)
    // {
    //     //since we are building a minHeap based on customer
    //     //age when age of customer a is less than age of
    //     //customer b we want a to be ordered before b
    //     if (a.age < b.age)
    //     {
    //         return true;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }

    bool operator()(customer a, customer b)
    {
        //since we are building a maxHeap based on customer
        //age when age of customer a is less than age of
        //customer b we want a to be ordered before b
        if (a.age > b.age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    priority_queue<customer, vector<customer>, customerAgeComp> m; // now it act as min heap

    m.push(customer("ustav", 20));
    m.push(customer("abc", 12));
    m.push(customer("efd", 32));
    m.push(customer("hij", 54));
    m.push(customer("nop", 45));
    m.push(customer("klm", 54));

    cout << m.size() << endl;

    while (!m.empty())
    {
        cout << m.top().name << " ";
        cout << m.top().age << " "; 
        cout << endl;
        m.pop();
    }

    cout << endl;
    cout << m.size() << endl;
}