#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

bool cmp(const string& a, const string& b)
{
    return a + b > b + a;
}

int main()
{
    vector<string> v;
    v.push_back("129");
    v.push_back("97");
    v.push_back("998");
    v.push_back("67");

    sort(v.begin(),v.end(), cmp);
    for(string a : v)
    {
        cout << a << " "; 
    }
}