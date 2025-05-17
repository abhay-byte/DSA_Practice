#include<iostream>
using namespace std;

int main(){

    int k = 3;
    int val = 42;

    int mask = ~(1 << k);
    cout << endl << (val&mask) << endl;
    return 0;
}