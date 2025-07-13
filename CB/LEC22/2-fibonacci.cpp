#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int f(int n)
{
    // create a base case, cases which are invalid, and we know the answers.
    if(n == 0 || n == 1)
    {
        return n;
    }

    // recursive case
    // f(n) = find n!
    // 1. ask your friend to find n-1th fibonacci no.
    int a = f(n-1);
    // 2. ask your friend to find n-2th fibonacci no.
    int b = f(n-2);

    return a + b;
}

int main()
{
    int n = 5;

    cout << f(n) << endl;
}