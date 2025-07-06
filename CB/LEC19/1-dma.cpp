#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{

    int* ptr = new int;

    *ptr = 50;

    cout << *ptr << endl;

    char* chrptr = new char;

    *chrptr = 'A';

    cout << *chrptr << endl;

    double* dptr = new double;

    *dptr = 3.14;

    cout << *dptr << endl;
    
}