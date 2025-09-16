#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n; //no of shops
    cin >> n;
    vector<int> x; //price at each shop

    for(int i = 0; i < n; i++)
    {
        int t = 0;
        cin >> t;

        x.push_back(t);
    }

    int q = 0; //no of days to buy the drink
    cin >> q;
    vector<int> m;
    for(int i = 0; i < q; i++)
    {
        int t = 0;
        cin >> t;
        m.push_back(t);
    }

    sort(x.begin(),x.end());
    vector<int> result;
    for(int i = 0; i < q; i++)
    {
        int c = m[i];
        int noOfShops = 0;
        for(int j = 0; j < n; j++)
        {
            if(x[j] <= m[i])
            {
                noOfShops++;
            }
            else
            {
                result.push_back(noOfShops);
                break;
            }
        }
    }

    cout << endl;
    for(int i: result)
    {
        cout << i << endl;
    }

}

/*
5
3 10 8 6 11
4
1
10
3
11
*/