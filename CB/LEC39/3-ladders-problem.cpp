#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int cnt1 = 0;
// time: O(k^n)
// space: O(n)

int f(int n, int k)
{
    // base case
    if (n == 0)
    {
        // count the no of ways to reach the 0th steps from 0th step
        return 1;
    }

    // recursive case
    // f(n,k) = count the no of ways to reach the nth step from the 0th step
    int cnt = 0;

    for (int j = 1; j <= k; j++)
    {
        // can you reach the nth step from the n-jth step?
        if (n - j >= 0)
        {
            // you can reach the nth step from the n-jth step,

            // now ask your friend to count the no of ways to reach n-jth steps from the 0th step
            cnt += f(n - j, k);
        }
    }

    return cnt;
}

int cnt2 = 0;

// time: O(n)
// space: O(n) due to fn call stack and dp []
int fTopDown(int n, vector<int> &dp)
{
    cnt2++;
    return 0;
}

// time: O(n.k)
// space: O(n)
int fBottomUp(int n, int k)
{
    vector<int> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        // find the no of ways to reach the nth step from the 0th step
        int cnt = 0;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
                cnt += dp[i - j];
        }
        dp[i] = cnt;
    }

    return dp[n];
}

// time: O(n)
// space: O(n), try to optimize this as well HW...
int fBottomUpOptimized(int n, int k)
{
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = dp[0];

    for (int i = 2; i <= k; i++)
    {
        dp[i] = 2 * dp[i - 1];
    }

    for (int i = k + 1; i <= n; i++)
    {
        dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
    }

    return dp[n];
}

int main()
{
    int n = 4;
    int k = 3;

    cout << f(n, k) << endl;
    cout << fBottomUp(n, k) << endl;
    cout << fBottomUpOptimized(n, k) << endl;
}