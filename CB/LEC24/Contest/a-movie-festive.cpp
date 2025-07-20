#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // taking input values, n, and an,bn
    // contraints, 1<=n<=2*10^5
    //           , 1<=a,b<=10^9

    int n;
    vector<vector<int>> ab;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        int b;

        cin >> a;
        cin >> b;

        ab.push_back({b, a});
    }

    sort(ab.begin(), ab.end());

    int s = ab[0][1];
    int e = ab[0][0];
    int cnt = 1;
    for (int i = 1; i < ab.size(); i++)
    {
        int st = ab[i][1];
        int ed = ab[i][0];
        if (e <= st && st > s)
        {
            cnt++;
            e = ed;
            s = st;
        }
    }

    cout << cnt << endl;
}

/*
output:

12
1 1
2 3
6 9
3 6
7 11
5 6
2 2
3 3
4 4
5 5 
6 6
7 7
*/