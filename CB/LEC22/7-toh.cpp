#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// time: O(log(y))
// space: O(log(y))

int f(int n, char src, char dst, char hlp)
{
    // base case
    if(n==0){
        return;
    }
    // recursive case

    // f(n) = move n disk from scr('A') to dst('C') using hlp('B')

    

}

int main()
{
    int n = 4;

    f(n, 'A','C','B');

    return 0;
}