#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> input = {60, 50, 10, 20, 30, 40};
    int k = 3;
    priority_queue<int> maxHeap(input.begin(),input.end()); 

    int i = 0;
    while(i < k)
    {
        int top = maxHeap.top();
        cout << top << " ";
        maxHeap.pop();
        i++;
    }

}