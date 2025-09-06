#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int main()
{
    //time: O(nlogn)
    //space: O(n)
    vector<int> input = {4,3,2,6};

    priority_queue<int, vector<int>, greater<int>> m(input.begin(),input.end()); 

    int total = 0;
    while(m.size() >1)
    {
        int firstSmallest = m.top();
        m.pop();

        int secondSmallest = m.top();
        m.pop();

        int merge_cost = firstSmallest + secondSmallest;
        total += merge_cost;

        m.push(merge_cost);
    }

    cout << total << endl;

}