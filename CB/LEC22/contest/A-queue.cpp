#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    vector<int> ti;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        ti.push_back(temp);
    }

    sort(ti.begin(), ti.end());

    int sum = 0;
    int noOfPeopleDisappointed = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum > ti[i])
        {
            noOfPeopleDisappointed++;
            sum += ti[i];
        }
        else
        {
            sum += ti[i];
        }
    }

    cout << n - noOfPeopleDisappointed << endl;
}