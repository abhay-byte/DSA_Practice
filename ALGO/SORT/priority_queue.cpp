#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> pq;  // Max-heap by default

    // Add elements to the priority queue
    pq.push(10);
    pq.push(40);
    pq.push(30);
    pq.push(50);
    pq.push(20);

    cout << "Priority Queue (Max Heap): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> pq1;  // Min-heap

    // Add elements to the priority queue
    pq1.push(10);
    pq1.push(40);
    pq1.push(30);
    pq1.push(50);
    pq1.push(20);

    cout << "Priority Queue (Min Heap): ";
    while (!pq1.empty()) {
        cout << pq1.top() << " ";
        pq1.pop();
    }
    cout << endl;

    return 0;
}

