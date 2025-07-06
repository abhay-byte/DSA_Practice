#include<iostream>
using namespace std;

int* f()
{
    int* ptr = new int();
    *ptr = 10;
    return ptr;
}

int main()
{

    int* ptr = f();

    cout << *ptr << endl;

    return 0;
    
}