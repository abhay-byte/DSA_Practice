/*

//https://hack.codingblocks.com/app/contests/7855/455/problem

Implement a Queue using two stacks Make it Dequeue efficient.
Input Format

Enter the size of the queue N add 0 - N-1 numbers in the queue
Constraints

Output Format

Display the numbers in the order they are dequeued and in a space separated manner
Sample Input

5

Sample Output

0 1 2 3 4

*/

#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> dequeue_stack;  // Main stack - for dequeue operations
    stack<int> enqueue_stack;  // Auxiliary stack - for enqueue operations
    
public:
    // Enqueue operation - O(n)
    void enqueue(int x) {
        // Step 1: Move all elements from dequeue_stack to enqueue_stack
        while (!dequeue_stack.empty()) {
            enqueue_stack.push(dequeue_stack.top());
            dequeue_stack.pop();
        }
        
        // Step 2: Push new element to enqueue_stack
        enqueue_stack.push(x);
        
        // Step 3: Move everything back to dequeue_stack
        while (!enqueue_stack.empty()) {
            dequeue_stack.push(enqueue_stack.top());
            enqueue_stack.pop();
        }
    }
    
    // Dequeue operation - O(1)
    int dequeue() {
        if (dequeue_stack.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        
        int front = dequeue_stack.top();
        dequeue_stack.pop();
        return front;
    }
    
    // Check if queue is empty
    bool isEmpty() {
        return dequeue_stack.empty();
    }
    
    // Get front element without removing
    int front() {
        if (dequeue_stack.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return dequeue_stack.top();
    }
};

int main() {
    int n;
    cin >> n;
    
    QueueUsingStacks queue;
    
    // Enqueue elements 0 to n-1
    for (int i = 0; i < n; i++) {
        queue.enqueue(i);
    }
    
    // Dequeue all elements and print
    bool first = true;
    while (!queue.isEmpty()) {
        if (!first) {
            cout << " ";
        }
        cout << queue.dequeue();
        first = false;
    }
    cout << endl;
    
    return 0;
}