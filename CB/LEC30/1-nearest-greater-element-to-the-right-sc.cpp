#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> A = {5, 3, 6, 7, 2, 1, 4};
    vector<int> ans;
    stack<int> s;
    int n = A.size();

    for(int i : A)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int i = n - 1; i >= 0; i--)
    {
        while(!s.empty() && s.top() <= A[i])
        {
            s.pop();
        }

        if(s.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(s.top());
        }

        s.push(A[i]);
    }

    reverse(ans.begin(),ans.end());

    for(int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}