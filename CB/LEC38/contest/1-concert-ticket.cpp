#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int m;
    vector<int> h;
    vector<int> t;

    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        h.push_back(temp);
    }

    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        t.push_back(temp);
    }
    sort(h.begin(),h.end());
    vector<int> result;
    for (int i = 0; i < m; i++)
    {
        int l = 0;
        int r = h.size()-1;
        int temp = -1;
        while (l < r)
        {
            int lprice = h[l];
            int rprice = h[r];
            int custPrice = t[i];
            if (lprice == custPrice)
            {
                temp = l;
                break;
            }
            if (rprice == custPrice)
            {
                temp = r;
                break;
            }
            if (lprice < custPrice && lprice > temp)
            {
                temp = l;
            }
            if (rprice < custPrice && rprice > temp)
            {
                temp = r;
            } 
            l++;
            r--;
        }
        if (temp != -1)
        {
            result.push_back(h[temp]);
            h.erase(h.begin()+temp);
        }
        else
        {
            result.push_back(-1);
        }
    }

    //reverse(result.begin(), result.end());

    for (int i : result)
    {
        cout << i << endl;
    }
}

/*
5 3
5 3 7 8 5
4 8 3

5 3
1 3 9 2 3
10 3 6
*/