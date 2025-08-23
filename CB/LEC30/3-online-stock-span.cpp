#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> f(vector<int>& A)
{
    stack<pair<int,int>> s;

    vector<int> ans;

    int n = A.size();

    for(int i = 0; i < n; i++)
    {
        while(!s.empty() && s.top().first <= A[i]) {
            s.pop();
        }
        int j;
        if(s.empty())
        {
            j = -1;
        }
        else{
            j = s.top().second;
        }

        ans.push_back( i - j);
        s.push({A[i],i});
    }

    return ans;
}

int main()
{
    vector<int> A = {100,80,60,70,60,75,85,200};
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