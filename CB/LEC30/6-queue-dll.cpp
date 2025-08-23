#include<iostream>
#include<list>
using namespace std;

template<typename T>
class queue{

    list<T> dll;

public:

    void push(T val)
    {
        dll.push_back(val);
    }

    void pop(){
        dll.pop_front();
    }

    int size()
    {
        return dll.size();
    }

    T front()
    {
        return dll.front();
    }

    bool empty()
    {
        return dll.empty();
    }


};