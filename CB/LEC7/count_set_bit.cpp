#include<iostream>
using namespace std;

int main(){

    int val = 42;
    int count=0;
    while(val>0)
    {
        if(1&val)
        {
            count++;
        }
        val = val >> 1;
    }
    cout << endl << count ;
}