/*

//https://hack.codingblocks.com/app/contests/7855/746/problem

Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

    enqueue(x) : Add an item x to rear of queue
    dequeue() : Remove an item from front of queue
    size() : Returns number of elements in queue.
    front() : Finds front item.

Input Format

First line consists of T test cases.
First line of every test case consists of 2 integers, N and K, denoting number of elements and number of elements to be reversed respectively.
Second line of every test case consists of elements of array.
Constraints

1 <= T <= 100
1 <= N <= 1000
1 <= K <= N
Output Format

For each testcase, in a new line, print the modified queue elements separated by space.
Sample Input

1
5 3
1 2 3 4 5

Sample Output

3 2 1 4 5 

Explanation

After Reversing First 3 elements of the Queue 1 2 3 4 5, it became 3 2 1 4 5.

*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstK(queue<int>& q, int k) {
    if (k <= 0 || k > q.size()) {
        return;
    }
    
    stack<int> st;
    
    // Step 1: Dequeue first K elements and push to stack
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }
    
    // Step 2: Pop from stack and enqueue back to queue
    // This reverses the first K elements
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    
    // Step 3: Move the remaining (n-k) elements from front to back
    // This maintains their original order
    int remaining = q.size() - k;
    for (int i = 0; i < remaining; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        queue<int> q;
        
        // Read elements and enqueue
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            q.push(x);
        }
        
        // Reverse first K elements
        reverseFirstK(q, k);
        
        // Print the modified queue
        bool first = true;
        while (!q.empty()) {
            if (!first) {
                cout << " ";
            }
            cout << q.front();
            q.pop();
            first = false;
        }
        cout << endl;
    }
    
    return 0;
}