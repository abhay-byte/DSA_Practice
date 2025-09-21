#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt1 = 0;
int f(int n)
{
    cnt1++;
    // create a base case, cases which are invalid, and we know the answers.
    if (n == 0 || n == 1)
    {
        return n;
    }

    // recursive case
    // f(n) = find n!
    // 1. ask your friend to find n-1th fibonacci no.
    int a = f(n - 1);
    // 2. ask your friend to find n-2th fibonacci no.
    int b = f(n - 2);

    return a + b;
}

int cnt2 = 0;

//time: O(n) ~ O(2n - 1)
//space: O(n) ~ O(2n)
int fTopDown(int n, vector<int> &dp)
{

    cnt2++;

    // look up
    if (dp[n] != -1)
    {
        // you have solved the f(n) previously so reuse the solution
        return dp[n];
    }

    // base case
    //  create a base case, cases which are invalid, and we know the answers.
    if (n == 0 || n == 1)
    {
        return dp[n] = n;
    }

    // recursive case

    return dp[n] = fTopDown(n - 1, dp) + fTopDown(n - 2, dp);
}

int cnt3 = 0;
int fBottomUp(int n)
{
    cnt3 = 0;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        cnt3++;
        //dp[i] = f(i) = ith fib no.
        dp[1] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int fBottomUpSpaceOptimized(int n)
{
    int a = 0;
    int b = 1;

    for(int i = 2; i <= n; i++)
    {
        //dp[i] = f(i) = ith fib no.
        int c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main()
{
    int n = 25;

    cout << f(n) << endl;

    vector<int> dp(n + 1, -1);

    cout << fTopDown(n, dp) << endl;

    cout << fBottomUp(n) << endl;

    cout << fBottomUpSpaceOptimized(n) << endl;

    cout << "Calls on Recurive Teq: " << cnt1 << ", Calls on DP-t: " << cnt2 << ", Calls on DP-b: " << cnt3 << endl;

}