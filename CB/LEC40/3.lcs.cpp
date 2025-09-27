#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// time : O(2^m+n),
int f(const string &s1, const string &s2, int m, int n, int i, int j)
{
    // base case
    if (i == m || j == n)
    {
        // cant find the lcs when s1 or s2 has ended, respective to s1 or s2
        return 0;
    }

    // recursive case

    // f(i,j) = find the lenght of lcs b/w s1[i...m-1] and s2[j...n-1]

    if (s1[i] == s2[j])
    {
        return 1 + f(s1, s2, m, n, i + 1, j + 1);
    }

    return max(f(s1, s2, m, n, i + 1, j), f(s1, s2, m, n, i, j + 1));
}

int fTopDown()
{
}

int fBottomUp(const string &s1, const string &s2, int m, int n)
{
    vector<vector<int>> dp(m+1,vector<int>(n+1,0)); // to set the nth row and mth column zero, base case

    for(int i = m - 1; i >= 0; i--)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            //dp[i][i] = f(i,j)
            if(s1[i] == s2[j])
            {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    return dp[0][0];
}

int main()
{
    string s1("ATGC");
    string s2("AGCT");

    int m = s1.size();
    int n = s2.size();

    cout << f(s1, s2, m, n, 0, 0) << endl;

    cout << fBottomUp(s1, s2, m, n) << endl;
}