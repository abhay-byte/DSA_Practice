#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int cnt1 = 0;
// time: O(3^n)
// space: O(n)
int f(int n)
{
    cnt1++;
    // base case
    if (n == 1)
    {
        // f(1) = find min no of steps required to reduce to 1 to 1
        return 0;
    }

    // recursive case

    // f(n) = find the min steps required to reduce to 1

    // option 1: reduce n to n-1

    int op1 = f(n - 1);

    // option 2: reduce n to n/2
    int op2 = INT_MAX;
    if (n % 2 == 0)
    {
        op2 = f(n / 2);
    }

    // option 3: reduce n to n/3
    int op3 = INT_MAX;
    if (n % 3 == 0)
    {
        op3 = f(n / 3);
    }

    return 1 + min(op1, min(op2, op3));
}

int cnt2 = 0;

// time: O(n)
// space: O(n) due to fn call stack and dp []
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
    if (n == 1)
    {
        // f(1) = find min no of steps required to reduce to 1 to 1
        return dp[n] = 0;
    }

    // recursive case

    // f(n) = find the min steps required to reduce to 1

    // option 1: reduce n to n-1

    int op1 = f(n - 1);

    // option 2: reduce n to n/2
    int op2 = INT_MAX;
    if (n % 2 == 0)
    {
        op2 = f(n / 2);
    }

    // option 3: reduce n to n/3
    int op3 = INT_MAX;
    if (n % 3 == 0)
    {
        op3 = f(n / 3);
    }

    return dp[n] = 1 + min(op1, min(op2, op3));
}

// time: O(n)
// space: O(n)
int fBottomUp(int n)
{
    vector<int> dp(n + 1);
    dp[1] = 0; // base case

    for (int i = 1; i <= n; i++)
    {
        // dp[i] = find min no of steps to reduce i to 1

        // decide next option

        // option 1:
        int op1 = dp[i - 1];

        // option 2: reduce n to n/2
        int op2 = INT_MAX;
        if (n % 2 == 0)
        {
            op2 = dp[i / 2];
        }

        // option 3: reduce n to n/3
        int op3 = INT_MAX;
        if (n % 3 == 0)
        {
            op3 = dp[i / 3];
        }

        dp[i] = 1 + min(op1, min(op2, op3));
    }

    return dp[n];
}

int main()
{
    int n = 100;

    cout << f(n) << endl;

    vector<int> dp(n + 1, -1);

    cout << fTopDown(n, dp) << endl;

    cout << fBottomUp(n) << endl;

    cout << "Calls on Recurive Teq: " << cnt1 << ", Calls on DP-t: " << cnt2 << endl;
}