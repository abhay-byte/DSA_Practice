#include <iostream>
#include <set>
using namespace std;

class customer
{
public:
    string name;
    int age;
    customer(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};

class ageCmp
{
    // return true if u want to a to be ordered before
    // otherwise return false
public:
    bool operator()(customer a, customer b) const
    {
        if (a.age < b.age)
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
    set<customer, ageCmp> s;

    s.insert(customer("a", 123));
    s.insert(customer("b", 13));
    s.insert(customer("c", 23));
    s.insert(customer("s", 1));
    s.insert(customer("d", 223));
    s.insert(customer("f", 12));
    s.insert(customer("g", 3));

    for(customer a: s)
    {
        cout << a.name << " " <<  a.age << endl;
    }
}