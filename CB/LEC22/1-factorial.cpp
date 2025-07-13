#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int f(int n)
{
    // create a base case
    if(n == 0)
    {
        return 1;
    }

    // recursive case
    // f(n) = find n!
    // 1. ask your friend to find n-1!
    int a = f(n-1);

    return n * a;
}

int main()
{
    int n = 5;

    cout << f(n) << endl;
}