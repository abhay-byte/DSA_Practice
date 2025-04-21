#include<iostream>
using namespace std;

int main(){

    int k = 3;
    int val = 42;

    int kthbit = val >> k;
    if(1&kthbit)
        cout << "bit is set";
    else
        cout << "bit is not set";
    return 0;
}