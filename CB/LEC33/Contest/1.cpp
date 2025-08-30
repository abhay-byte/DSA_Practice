#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n; //noOfApplicants
    int m; //noOfAppartments
    int k; //maxDiffAllowed

    cin >> n;
    cin >> m;
    cin >> k;

    vector<int> desiredAppartments;
    vector<int> appartmentSize;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        desiredAppartments.push_back(t);
    }
    for(int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        appartmentSize.push_back(t);
    }

    sort(desiredAppartments.begin(), desiredAppartments.end());
    sort(appartmentSize.begin(),appartmentSize.end());

    int cnt = 0;
    int j = 0;
    for(int i = 0; i < appartmentSize.size() && j < desiredAppartments.size(); i)
    {
        if(desiredAppartments[j] - k <= appartmentSize[i] )
        {
            if(desiredAppartments[j] + k >= appartmentSize[i])
            {
                cnt++;
                i++;
                j++;
                continue;
            }
            else{
                j++;
            }

        }
        else{
            i++;
        }

    }

    cout << cnt << endl;
}

/*
4 3 5
60 45 80 60
30 60 75

6 7 10
60 45 64 78 98 123
100 50 50 30 120 150 700
*/