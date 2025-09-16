#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> input = {60, 50, 10, -1, 20, 30, -1,40,-1};
    int k = 3;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int i = 0;
    while (i < k && input[i] != -1)
    {
        minHeap.push(input[i]);
        i++;
    }

    while (i < input.size())
    {
        while (input[i] != -1)
        {
            if (minHeap.top() < input[i])
            {
                minHeap.pop();
                minHeap.push(input[i]);
            }
            i++;
        }
        i++;

        int j = 0;
        vector<int> pop;
        while (j < k)
        {
            cout << minHeap.top() << " ";
            pop.push_back(minHeap.top());
            minHeap.pop();
            j++;
        }
        cout << endl;
        while(!pop.empty())
        {
            minHeap.push(pop[0]);
        }
    }
}