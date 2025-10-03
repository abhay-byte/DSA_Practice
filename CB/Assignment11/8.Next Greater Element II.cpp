/*

//https://hack.codingblocks.com/app/contests/7855/2111/problem

Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.
Input Format

First line contains N - size of array.
Second line contains N space separated integers denoting array elements.
Constraints

2 <= Array.length <= 106
Output Format

Output the resultant array in a single line in space separated manner.
Sample Input

3
1 2 1

Sample Output

2 -1 2

Explanation

The first 1's next greater number is 2; The number 2 can't find next greater number; The second 1's next greater number needs to search circularly, which is also 2.

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);  // Initialize all with -1
    stack<int> st;  // Stack stores indices
    
    // Traverse the array twice to handle circular nature
    // We process indices from 0 to 2n-1, but use modulo to wrap around
    for (int i = 0; i < 2 * n; i++) {
        int currentIndex = i % n;
        int currentValue = nums[currentIndex];
        
        // Pop elements from stack that are smaller than current element
        // These elements have found their next greater element
        while (!st.empty() && nums[st.top()] < currentValue) {
            int index = st.top();
            st.pop();
            result[index] = currentValue;
        }
        
        // Only push indices in first traversal (0 to n-1)
        // Second traversal is just to find next greater for pending elements
        if (i < n) {
            st.push(i);
        }
    }
    
    // Elements still in stack don't have next greater element
    // They are already initialized to -1
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    vector<int> result = nextGreaterElements(nums);
    
    // Print result
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}