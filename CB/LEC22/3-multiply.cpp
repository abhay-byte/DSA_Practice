#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int f(int x , int y)
{
    // create a base case, cases which are invalid, and we know the answers.
    if(y == 0)
    {
        return 0;
    }

    // recursive case
    // f(n) = find n!
    // 1. ask your friend to find n-1th fibonacci no.
    int a = f(x,y-1);

    return a + x;
}

int main()
{
    int x = 5; int y = 4;

    cout << f(x,y) << endl;
}