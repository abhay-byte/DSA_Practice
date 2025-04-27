#include<iostream>
using namespace std;

int main(){

    int a[] = {2,5,7,8,5,7,8,3,3};
    int result = 0;

    for(int i: a)
        result ^=i;

    cout << result;
    return 0;
}
