#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<vector<int>> v;

int sum(vector<int> &a)
{
    int s = 0;
    for (int i = 0; i < a.size(); i++)
    {
        s += a[i];
    }
    return s;
}

int mex(const vector<int> &a) {

    unordered_set<int> s(a.begin(), a.end());

    int m = 0;

    while (s.count(m)) {
        m++;
    }
    return m;
}


int findMaxScoreFromSubsets(vector<int> &a, int p)
{
    int score = 0;
    int cnt = 0;
    vector<int> temp;
    while (a.size() > 1 || temp.size() > 0)
    {
        cnt++;
        temp.push_back(a.back());
        a.pop_back();
        if (cnt > 1)
        {
            int s = sum(temp);
            int m = mex(temp);
            score += max(s, m);
            temp.clear();
            cnt = 0;
        }
    }

    if (!a.empty())
    {
        if (a[0] == 0)
        {
            score += 1;
        }
        else
        {
            score += 0;
        }

        if (a[0] != 0)
        {
            score += a[0];
        }
    }
    return score;
}

int main()
{

    int t = 0;
    int n = 0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        v.push_back(a);
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << findMaxScoreFromSubsets(v[i], i) << endl;
    }
}
/*
1
7
0 1 2 3 4 50 60

1
10
0 12 245  3 3 1 0 9 87 1

1
10
2 12 245  3 3 1 3 9 87 1

1
9
2 12 245  3 3 1 3 9 87

1
2
0 1

1
50
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
31 32 33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48 49 50
*/