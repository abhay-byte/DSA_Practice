#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int cnt1 = 0;
// time: O(2^n+m)
// space: O(n)

int f(vector<vector<int>> &grid, int m, int n, int i, int j)
{
    cnt1++;
    // base case
    if (i == m - 1 && j == n - 1)
    {
        return grid[i][j];
    }

    // recursive case

    // f(i,j) = find the min sum path from (i,j) to (m-1, n-1)

    if (i == m - 1)
    {
        return grid[i][j] + f(grid, m, n, i, j + 1);
    }

    if (j == n - 1)
    {
        return grid[i][j] + f(grid, m, n, i + 1, j);
    }

    int X = f(grid, m, n, i, j + 1);
    int Y = f(grid, m, n, i + 1, j);
    return grid[i][j] + min(X, Y);
}

int cnt2 = 0;

// time: O(nm)
// space: O(nm) due to fn call stack and dp []
int fTopDown(vector<vector<int>> &grid, int m, int n, int i, int j, vector<vector<int>> &dp)
{
    cnt2++;
    // look up

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // base case
    if (i == m - 1 && j == n - 1)
    {
        return dp[i][j] = grid[i][j];
    }

    // recursive case

    // f(i,j) = find the min sum path from (i,j) to (m-1, n-1)

    if (i == m - 1)
    {
        return dp[i][j] = grid[i][j] + fTopDown(grid, m, n, i, j + 1, dp);
    }

    if (j == n - 1)
    {
        return dp[i][j] = grid[i][j] + fTopDown(grid, m, n, i + 1, j, dp);
    }

    int X = fTopDown(grid, m, n, i, j + 1, dp);
    int Y = fTopDown(grid, m, n, i + 1, j, dp);

    return dp[i][j] = grid[i][j] + min(X, Y);
}

// time: O(mn)
// space: O(nm)
int fBottomUp(vector<vector<int>> &grid, int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1)
            {
                dp[i][j] = grid[i][j];
            }
            else if (i == m - 1)
            {
                dp[i][j] = grid[i][j] + dp[i][j + 1];
            }
            else if (j = n - 1)
            {
                dp[i][j] = grid[i][j] + dp[i + 1][j];
            }
            else
            {
                dp[i][j] = grid[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    return dp[0][0];
}

// time: O(nm)
// space: O(n), try to optimize this as well HW...
int fBottomUpOptimized(vector<vector<int>> &grid, int m, int n)
{
    vector<int> dp(n);

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1)
            {
                dp[j] = grid[i][j];
            }
            else if (i == m - 1)
            {
                dp[j] = grid[i][j] + dp[j + 1];
            }
            else if (j = n - 1)
            {
                dp[j] = grid[i][j] + dp[j];
            }
            else
            {
                dp[j] = grid[i][j] + min(dp[j + 1], dp[j]);
            }
        }
    }
    return dp[0];
}

int main()
{
    vector<vector<int>> grid = {
        {1, 2, 3},
        {1, 5, 1},
        {4, 2, 1}};
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << f(grid, m, n, 0, 0) << endl;
    cout << fTopDown(grid, m, n, 0, 0, dp);
    cout << fBottomUp(grid, m, n);
    cout << fBottomUpOptimized(grid, m, n);
    cout << endl;
    cout << "cnt1: " << cnt1 << " cnt2: " << cnt2 << endl;
    return 0;
}