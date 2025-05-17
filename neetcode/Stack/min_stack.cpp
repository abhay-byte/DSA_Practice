#include <iostream>
#include <set>
#include <stack>
#include <climits>

using namespace std;

class MinStack {
    stack<int> st;
    stack<int> min_st; 

    public:
        MinStack() {
            
        }
        
        void push(int val) {
            st.push(val);
            if (min_st.empty() || val <= min_st.top()) {
                min_st.push(val);
            }
        }
        
        void pop() {
            if (!st.empty() && !min_st.empty() && st.top() == min_st.top()) {
                min_st.pop();
           }
           if (!st.empty()) {
            st.pop();
         }
        }
        
        int top() {
            return st.top();
        }
        
        int getMin() {
            return min_st.top();
        }
    };

int main()
{
    MinStack minStack = MinStack();
minStack.push(1);
minStack.push(2);
minStack.push(0);
minStack.getMin(); // return 0
minStack.pop();
minStack.top();    // return 2
int val = minStack.getMin(); // return 1
}