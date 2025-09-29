#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define vvv vector<vector<vector<int>>>

using namespace std;

int f(vector<int> p, int i, int j, int y)
{
    // base case
    if (i == j)
    {
        return p[i] * y;
    }

    // recursive case

    // selling ith bottle option 1
    // selling jth bottle option 2

    return max(y * p[i] + f(p, i + 1, j, y + 1),
               y * p[j] + f(p, i, j - 1, y + 1));
}

int fTopDown(vector<int> p, int i, int j, int y, vvv &dp)
{
    // look up
    if (dp[i][j][y] != -1)
        return dp[i][j][y];

    // base case
    if (i == j)
    {
        return dp[i][j][y] = p[i] * y;
    }

    // recursive case

    // selling ith bottle option 1
    // selling jth bottle option 2

    return dp[i][j][y] = max(y * p[i] + fTopDown(p, i + 1, j, y + 1, dp),
                             y * p[j] + fTopDown(p, i, j - 1, y + 1, dp));
}

int fParameterOptimized(vector<int> p, int i, int j)
{
    int y = p.size() - j + i;
    // base case
    if (i == j)
    {
        return p[i] * y;
    }

    // recursive case

    // selling ith bottle option 1
    // selling jth bottle option 2

    return max(y * p[i] + fParameterOptimized(p, i + 1, j),
               y * p[j] + fParameterOptimized(p, i, j - 1));
}

int fTopDownParameterOptimized(vector<int> p, int i, int j, vector<vector<int>> &dp)
{
    int y = p.size() - j + i;
    // base case
    if (i == j)
    {
        return dp[i][j] = p[i] * y;
    }

    // recursive case

    // selling ith bottle option 1
    // selling jth bottle option 2

    return dp[i][j] = max(y * p[i] + fTopDownParameterOptimized(p, i + 1, j, dp),
                          y * p[j] + fTopDownParameterOptimized(p, i, j - 1, dp));
}

int fBottomUpParameterOptimized(vector<int> p, int n)
{
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        // int j = i;
        // int y = n;
        // int dp[i][j] = p[i] * y;
        dp[i][i] = p[i] * n;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            // dp[i][j] = f(i,j)
            int y = n - j + i;
            dp[i][j] = max(y * p[i] + dp[i + 1][j],
                           y * p[j] + dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}

int main()
{
    vector<int> p = {2, 3, 5, 1, 4};
    int n = p.size();

    vvv dp(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));

    cout << f(p, 0, n - 1, 1) << endl;

    cout << fTopDown(p, 0, n - 1, 1, dp) << endl;

    cout << fParameterOptimized(p, 0, n - 1) << endl; // state optimized

    vector<vector<int>> dp2(n, vector<int>(n, -1));

    cout << fTopDownParameterOptimized(p, 0, n - 1, dp2) << endl;

    cout << fBottomUpParameterOptimized(p, n);
}