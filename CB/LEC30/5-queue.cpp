#include<iostream>
#include<deque>
using namespace std;

template<typename T>
class queue{

    deque<T> d;

public:

    void push(T val)
    {
        d.push_back(val);
    }

    void pop(){
        d.pop_front();
    }

    int size()
    {
        return d.size();
    }

    T front()
    {
        return d.front();
    }

    bool empty()
    {
        return d.empty();
    }


};