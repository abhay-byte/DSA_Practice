#include <queue>
#include <iostream>

using namespace std;
void priority_queue_example() {
    priority_queue<int> pq;

    // Add
    pq.push(30);
    pq.push(10);
    pq.push(20);

    // Traverse (no iterator — use pop to view)
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    // Specialty: Always gives largest element first (max-heap)
}

void default_max_heap() {
    priority_queue<int> pq;

    pq.push(10);
    pq.push(5);
    pq.push(15);  // highest value has highest priority

    while (!pq.empty()) {
        cout << pq.top() << " "; // 15 10 5
        pq.pop();
    }
}

void min_heap_example() {
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(10);
    pq.push(5);
    pq.push(15);  // smallest value has highest priority

    while (!pq.empty()) {
        cout << pq.top() << " "; // 5 10 15
        pq.pop();
    }
}

struct Compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second; // min-heap by second
    }
};

//Custom Priority (Using Struct or Lambda)
void custom_priority() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    pq.push({1, 20});
    pq.push({2, 10});
    pq.push({3, 30});

    while (!pq.empty()) {
        cout << "(" << pq.top().first << ", " << pq.top().second << ") ";
        pq.pop();
    }
    // Output: (2, 10) (1, 20) (3, 30)
}
