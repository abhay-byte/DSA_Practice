#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    int n; int k; string s;

    cin >> n;
    cin >> k;
    cin >> s;

    sort(s.begin(),s.end());

    char temp = s[0];
    int maxSoFar = 0;
    int count = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(temp == s[i])
        {
            count++;
        }
        else{
            maxSoFar = max(maxSoFar,count);
            temp = s[i];
        }
    }

    if(maxSoFar > k)
        cout << "NO";
    else
        cout << "YES";
}