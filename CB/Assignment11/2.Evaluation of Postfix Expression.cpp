/*
//https://hack.codingblocks.com/app/contests/7855/376/problem


You are given a postfix expression . You need to evaluate the value of that Postfix Expression. Numbers would from 0 to 9 and operators are (+, -, *, /,%) ;
Input Format

First line contains integer t which is number of test case. For each test case, It contains a postfix expression.
Constraints

Output Format

Print the value of that expression.
Sample Input

1
231*+9-

Sample Output

-4

Explanation

Infix Expression = 2 + 3 * 1 - 9

*/

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;
    
    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        
        // If character is a digit, push it to stack
        if (isdigit(ch)) {
            st.push(ch - '0');  // Convert char to int
        }
        // If character is an operator
        else {
            // Pop two operands
            int operand2 = st.top(); st.pop();
            int operand1 = st.top(); st.pop();
            
            int result;
            
            // Apply the operator
            switch(ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '%':
                    result = operand1 % operand2;
                    break;
            }
            
            // Push result back to stack
            st.push(result);
        }
    }
    
    // Final result is at top of stack
    return st.top();
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline after reading t
    
    while (t--) {
        string expression;
        getline(cin, expression);
        
        // Remove any trailing whitespace
        while (!expression.empty() && isspace(expression.back())) {
            expression.pop_back();
        }
        
        int result = evaluatePostfix(expression);
        cout << result << endl;
    }
    
    return 0;
}