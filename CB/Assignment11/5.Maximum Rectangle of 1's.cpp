/*

//https://hack.codingblocks.com/app/contests/7855/1553/problem

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
Input Format

First line contains two integers n and m denoting rows and columns of a matrix. Next n lines contains m integers each representing the matrix.
Constraints

N and m will not be greater than 50
Output Format

An integer denoting maximum area of rectangle.
Sample Input

4 5
1 0 1 0 0 
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Sample Output

6

Explanation

Self Explanatory

*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Function to find the largest rectangle area in a histogram
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    
    for (int i = 0; i < n; i++) {
        // Pop elements from stack while current height is less
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int h = heights[st.top()];
            st.pop();
            
            // Calculate width
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }
    
    // Process remaining elements in stack
    while (!st.empty()) {
        int h = heights[st.top()];
        st.pop();
        int width = st.empty() ? n : n - st.top() - 1;
        maxArea = max(maxArea, h * width);
    }
    
    return maxArea;
}

// Function to find maximum rectangle area in binary matrix
int maximalRectangle(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxArea = 0;
    
    // Initialize height array
    vector<int> heights(cols, 0);
    
    // Process each row
    for (int i = 0; i < rows; i++) {
        // Update heights for current row
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                heights[j] += 1;  // Increment height
            } else {
                heights[j] = 0;   // Reset height
            }
        }
        
        // Find max rectangle in current histogram
        int area = largestRectangleArea(heights);
        maxArea = max(maxArea, area);
    }
    
    return maxArea;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> matrix(n, vector<int>(m));
    
    // Read matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // Find and print maximum rectangle area
    int result = maximalRectangle(matrix);
    cout << result << endl;
    
    return 0;
}