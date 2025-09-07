#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> input = {60, 50, 10, 20, 30, 40};
    int k = 3;
    priority_queue<int,vector<int>,greater<int>> minHeap; 

    int i = 0;
    while(i < k)
    {
        minHeap.push(input[i]);
        i++;
    }

    while(i < input.size())
    {
        if(minHeap.top() < input[i])
        {
            minHeap.pop();
            minHeap.push(input[i]);
        }
        i++;
    }

    i = 0;
    while(i < k)
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
        i++;
    }


}