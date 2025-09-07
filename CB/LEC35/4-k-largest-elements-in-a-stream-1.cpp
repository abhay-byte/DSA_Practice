#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void printMinHeap(priority_queue<int, vector<int>, greater<int>> minHeap)
{
    while(!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

int main()
{
    vector<int> input = {60, 50, 10, -1, 20, 30, -1,40,-1};
    int k = 3;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int i = 0;
    while (i < k)
    {
        int t;
        cin >> t;
        minHeap.push(t);
        i++;
    }

    while (true)
    {
        int val; cin >> val;

        if(val == 0)
        {
            break;
        }else if(val == -1)
        {
            printMinHeap(minHeap);
        }
        else{
            if(val > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(val);
            }
        }
    }
}

/*
input: 60 50 10 -1 20 30 -1 40 -1 0
*/