/*

//https://hack.codingblocks.com/app/contests/7855/1955/problem

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.
Input Format

Two Input strings S and T.
Constraints

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Output Format

true or false
Sample Input

"ab#c"
"ad#c"

Sample Output

true

Explanation

Both S and T become "ac"

*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to process string with backspaces
string processString(string s) {
    stack<char> st;
    
    for (char ch : s) {
        if (ch != '#') {
            // Regular character, push to stack
            st.push(ch);
        } else {
            // Backspace character
            if (!st.empty()) {
                st.pop();
            }
        }
    }
    
    // Build the final string from stack
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    
    return result;
}

// Compare two strings after processing backspaces
bool backspaceCompare(string S, string T) {
    string processedS = processString(S);
    string processedT = processString(T);
    
    return processedS == processedT;
}

int main() {
    string S, T;
    cin >> S >> T;
    
    // Remove quotes if present in input
    if (S.front() == '"' && S.back() == '"') {
        S = S.substr(1, S.length() - 2);
    }
    if (T.front() == '"' && T.back() == '"') {
        T = T.substr(1, T.length() - 2);
    }
    
    bool result = backspaceCompare(S, T);
    
    if (result) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}