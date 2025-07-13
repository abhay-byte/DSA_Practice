#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// time: O(log(y))
// space: O(log(y))

int f(int x, int y)
{
    // create a base case, cases which are invalid, and we know the answers.
    if (y == 0)
    {
        return 1;
    }

    // recursive case
    // f(n) = find n!
    // 1. ask your friend to find n-1th fibonacci no.
    int a = f(x, y / 2); // saving a is mandatory here

    if(y % 2 == 0)
    {
        // y is even
        return a * a;
    }
    else
    {   
        // y is odd
        return x * a * a;
    }
}

int main()
{
    int x = 2;
    int y = 8;

    cout << f(x, y) << endl;
}