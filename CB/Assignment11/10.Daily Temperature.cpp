/*

//https://hack.codingblocks.com/app/contests/7855/3815/problem

You want warmer days to go outside the home.

You are given an array of integers temperatures represents the daily temperatures, print an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.

If there is no future day for which this is possible, keep answer[i] == 0 instead.
Input Format

First line contains an integer n .
Second line contains an integer array of size n.
Constraints

1<= n <= 104
30 <= temperatures[i] <= 100
Output Format

Print the answer array.
Sample Input

8 
73 74 75 71 69 72 76 73

Sample Output

1 1 4 2 1 1 0 0

Explanation

self-explanatory

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);  // Initialize all with 0
    stack<int> st;  // Stack stores indices
    
    // Traverse temperatures from left to right
    for (int i = 0; i < n; i++) {
        // Pop indices where current temperature is warmer
        while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
            int prevIndex = st.top();
            st.pop();
            // Calculate days to wait: current index - previous index
            answer[prevIndex] = i - prevIndex;
        }
        
        // Push current index to stack
        st.push(i);
    }
    
    // Indices still in stack have no warmer day ahead
    // They are already initialized to 0
    
    return answer;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> temperatures(n);
    for (int i = 0; i < n; i++) {
        cin >> temperatures[i];
    }
    
    vector<int> answer = dailyTemperatures(temperatures);
    
    // Print result
    for (int i = 0; i < n; i++) {
        cout << answer[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}