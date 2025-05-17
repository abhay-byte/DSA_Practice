#include<iostream>
using namespace std;

int main(){

    int a = 25;
    int b = 19;

    int c = a & b;
    int d = a | b;
    int e = a ^ b;
    int f = ~a;

    cout << endl;
    cout << "a&b: " << c << endl;
    cout << "a|b: " << d << endl;
    cout << "a^b: " << e << endl;
    cout << "~a: " << f << endl;

    return 0;
}