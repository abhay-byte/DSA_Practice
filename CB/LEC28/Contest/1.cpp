#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> a;
    for(int i = 0; i < n; i++)
    {
        int t1; int t2;
        cin >> t1;
        cin >> t2;
        a.push_back({t1,t2});
    }

    sort(a.begin(), a.end());

    int latest = a[0][1];
    int cnt = 1;
    int maxSoFar = 0;
    for(int i = 0; i < n-1; i++)
    {
        int t1 = a[i][1];
        int t2 = a[i+1][0];
        if(t1 >= t2){
            cnt++;
        }
        if(latest < t1)
        {   
            cnt--;
            latest = t1;
        }
        maxSoFar = max(maxSoFar,cnt);
    }

    cout << cnt;

}

/*
3
5 8
2 4
3 9

5
1 8
3 5
4 7
5 8
6 9

1
1 4

2
1 2
3 4
*/