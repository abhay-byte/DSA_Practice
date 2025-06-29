#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int longestGoodStrings(const string& str)
{
    int cnt = 0;
    int maxSoFar = 0;

    for(char ch: str)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o'|| ch == 'u')
        {
            cnt++;
            maxSoFar = max(maxSoFar, cnt);
        }
        else
        {
            cnt = 0;
        }
    }

    return maxSoFar;

}

int main()
{
    string s = "aeiouadf";
    cout << longestGoodStrings(s);
}