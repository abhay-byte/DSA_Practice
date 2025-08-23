#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> f(vector<int>& A)
{
    int n = A.size();
    vector<int> ans(n, -1);
    stack<pair<int,int>> s;

    for(int i = 0; i < n; i++)
    {
        while(!s.empty() && A[i] > s.top().first)
        {
            ans[s.top().second = A[i]];
            s.pop();
        }

        s.push({A[i],i});
    }

    return ans;
}

int main()
{
    vector<int> A = {5, 3, 6, 7, 2, 1, 4};
    vector<int> ans = f(A);

    for(int i : A)
    {
        cout << i << " ";
    }
    cout << endl;

    for(int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}