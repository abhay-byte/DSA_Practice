/*
//https://hack.codingblocks.com/app/contests/7855/347/problem



Given a Queue consisting of first n natural numbers (in random order). The task is to check whether the given Queue elements can be arranged in increasing order in another Queue using a stack. The operation allowed are:

    Push and pop elements from the stack
    Pop (Or enqueue) from the given Queue.
    Push (Or Dequeue) in the another Queue.

Input Format

The First Line contains an Integer T, as the number of Test cases. Next Line contains an Integer N, as the Number Elements in the Queue. Next Line contains N Integers as the Value to be inserted in the Queue.
Constraints

Output Format

Print Yes if such a arrangement is possible otherwise print No.
Sample Input

2
5
5 1 2 3 4 
6
5 1 2 6 3 4 

Sample Output

Yes
No

Explanation

For the First Test Case, Queue = {5, 1, 2, 3, 4 }
Pop the first element of the given Queue i.e 5.
Push 5 into the stack.
Now, pop all the elements of the given Queue and push them to second Queue.
Now, pop element 5 in the stack and push it to the second Queue.


*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool canBeSorted(queue<int> q, int n) {
    stack<int> st;
    int expected = 1; // We expect numbers from 1 to n in order
    
    while (expected <= n) {
        // Case 1: If stack top has the expected element
        if (!st.empty() && st.top() == expected) {
            st.pop();
            expected++;
        }
        // Case 2: If queue front has the expected element
        else if (!q.empty() && q.front() == expected) {
            q.pop();
            expected++;
        }
        // Case 3: Move element from queue to stack
        else if (!q.empty()) {
            int val = q.front();
            q.pop();
            
            // Check if we can push this onto stack
            // Stack must maintain decreasing order (top to bottom)
            if (!st.empty() && st.top() < val) {
                // Can't maintain decreasing order
                return false;
            }
            st.push(val);
        }
        // Case 4: Queue is empty but stack top doesn't match
        else {
            return false;
        }
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            q.push(val);
        }
        
        if (canBeSorted(q, n)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}