#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

bool cmp(string a, string b)
{
    if(a.size() < b.size())
    {
        return true;
    }
    return false;
}

int main()
{
    vector<string> v;
    v.push_back("aaaa");
    v.push_back("z");
    v.push_back("yy");
    v.push_back("ccc");

    sort(v.begin(),v.end(), cmp);
    for(string a : v)
    {
        cout << a << " "; 
    }
}