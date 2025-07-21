#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    // taking input n and t
    // taking kn inputs
    // contraints, 1<=n<=2*10^5
    //           , 1<=t, ki<=10^9

    int n;
    int t;
    vector<int> k;
    cin >> n;
    cin >> t;
    // map<int,int> k;

    for (int i = 0; i < n; i++)
    {
        int ti = 0;
        cin >> ti;

        k.push_back(ti);
        // k.insert(ti,1);
    }

    sort(k.begin(), k.end());

    int max = k[k.size() - 1];

    int time = max;
    int cnt = 0;
    while (true)
    {
        int val = 0;
        int temptime = 0;
        for (int i = 0; i < k.size(); i++)
        {
            if (val >= t)
            {
                time = temptime;
                break;
            }
            val += time / k[i];
            temptime += k[i];
        }

        time += max;
    }
    cout << time;
}

/*
test case:-

3 7
3 2 5

*/