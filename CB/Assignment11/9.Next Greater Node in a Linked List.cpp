/*

//https://hack.codingblocks.com/app/contests/7855/3777/problem

You are given the head of a linked list with n nodes.

Your task is to find the value of the next greater node for each node in the list. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Print an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.
Input Format

First line contains N length of the Linked List.
Second line contains node values of the Linked List.
Constraints

The number of nodes in the list is N.
1 <= n <= 104
1 <= Node.val <= 109
Output Format

Print next greater node of every every node.
Sample Input

3
 2 1 5

Sample Output

5 5 0

Explanation

5 is greater than 2.
5 is greater than 1.
No element is greater than 5 now so answer[i]=0.
Hence [5, 5, 0]

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

vector<int> nextLargerNodes(ListNode* head) {
    // Step 1: Convert linked list to vector for easier access
    vector<int> values;
    ListNode* current = head;
    while (current != nullptr) {
        values.push_back(current->val);
        current = current->next;
    }
    
    int n = values.size();
    vector<int> result(n, 0);  // Initialize with 0s
    stack<int> st;  // Stack stores indices
    
    // Step 2: Traverse from left to right
    for (int i = 0; i < n; i++) {
        // Pop indices from stack where current value is greater
        // These indices have found their next greater element
        while (!st.empty() && values[st.top()] < values[i]) {
            int index = st.top();
            st.pop();
            result[index] = values[i];
        }
        
        // Push current index to stack
        st.push(i);
    }
    
    // Elements still in stack don't have next greater element
    // They are already initialized to 0
    
    return result;
}

// Alternative approach: Traverse from right to left
vector<int> nextLargerNodesRightToLeft(vector<int>& values) {
    int n = values.size();
    vector<int> result(n, 0);
    stack<int> st;  // Stack stores values
    
    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from stack that are <= current element
        while (!st.empty() && st.top() <= values[i]) {
            st.pop();
        }
        
        // Top of stack is the next greater element (if exists)
        if (!st.empty()) {
            result[i] = st.top();
        }
        
        // Push current element to stack
        st.push(values[i]);
    }
    
    return result;
}

ListNode* createLinkedList(vector<int>& values) {
    if (values.empty()) return nullptr;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    
    for (int i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    
    return head;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    ListNode* head = createLinkedList(values);
    vector<int> result = nextLargerNodes(head);
    
    // Print result
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}