#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    pair<int, int> p1;

    p1.first = 10;
    p1.second = 20;

    pair<string, int> p2 = {"Abhay", 20};

    pair<char, int> p3 = make_pair('X', 0);

    pair<string, string> p4;

    cin >> p4.first >> p4.second;

    vector<pair<int,int>> v1;

    int n = 3;
    for(int i = 0; i < n; i++)
    {
        int x,y;
        x = i; y = i%2;
        v1.push_back({x,y});
    }

    sort(v1.begin(),v1.end()); //by default sorting on first element
    //if value of first pair is same then value of second pair is done
    //make comp for sort pair of second element
    for(pair<int,int> p: v1)
    {
        cout << p.first << " " << p.second << "\n";
    }
}
