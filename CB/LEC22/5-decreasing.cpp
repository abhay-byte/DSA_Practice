#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void f(int n)
{
    // create a base case, cases which are invalid, and we know the answers.
    if (n == 0)
    {
        return;
    }

    // recursive case
    // f(n) = find n!
    // 1. ask your friend to to print 1 to n-1 increasing order


    cout << n << " ";

    f(n - 1);

}

int main()
{
    int n = 5;

    f(n);
}