/*

//https://hack.codingblocks.com/app/contests/7855/1682/problem

Given an encoded string, return its decoded string.

The encoding rule is: k[encodedstring], where the encodedstring inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
Input Format

First line contains the string s.
Constraints

None
Output Format

Print the decoded string
Sample Input

3[a]2[bc]3[ee]2[r]

Sample Output

aaabcbceeeeeerr

Explanation

None

*/

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string decodeString(string s) {
    stack<char> st;
    
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        
        if (ch != ']') {
            // Push everything except ']' to stack
            st.push(ch);
        } else {
            // Found ']', start decoding
            
            // Step 1: Extract the string inside brackets
            string decodedStr = "";
            while (!st.empty() && st.top() != '[') {
                decodedStr = st.top() + decodedStr;
                st.pop();
            }
            
            // Step 2: Pop the '[' bracket
            st.pop();
            
            // Step 3: Extract the number k (could be multi-digit)
            string numStr = "";
            while (!st.empty() && isdigit(st.top())) {
                numStr = st.top() + numStr;
                st.pop();
            }
            int k = stoi(numStr);
            
            // Step 4: Repeat the decoded string k times
            string repeatedStr = "";
            for (int j = 0; j < k; j++) {
                repeatedStr += decodedStr;
            }
            
            // Step 5: Push the repeated string back to stack
            for (char c : repeatedStr) {
                st.push(c);
            }
        }
    }
    
    // Build final result from stack
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    
    return result;
}

int main() {
    string s;
    cin >> s;
    
    string decoded = decodeString(s);
    cout << decoded << endl;
    
    return 0;
}