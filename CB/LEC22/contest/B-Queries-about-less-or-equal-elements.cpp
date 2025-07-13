#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a; int b;
    vector<int> ai; vector<int> bi;

    cin >> a; cin >> b;
    for(int i = 0; i < a; i++)
    {
        int t;
        cin >> t;
        ai.push_back(t);
    }

    for(int i = 0; i < b; i++)
    {
        int t;
        cin >> t;
        bi.push_back(t);
    }

    sort(ai.begin(),ai.end());

    int s = 0; int e = a-1;
    for(int i = 0; i < b; i++)
    {
        while(true)
        {
            
        }
    }

}