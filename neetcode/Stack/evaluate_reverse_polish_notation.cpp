#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <climits>
#include <string>
using namespace std;

class Solution {
    public:
        stack<int> st_n;
        int evalRPN(vector<string>& tokens) {
            for(string itr: tokens)
            {
                if(itr == "+" || itr == "-" || itr == "*" || itr == "/")
                {
                    int op1 = st_n.top();
                    st_n.pop();
                    int op2 = st_n.top();
                    st_n.pop();

                    if(itr == "+")
                    {
                        st_n.push(op2 + op1);
                    }
                    else if(itr == "-")
                    {
                        st_n.push(op2 - op1);    
                    }
                    else if(itr == "*")
                    {
                        st_n.push(op2 * op1);
                    }
                    else if(itr == "/")
                    {
                        st_n.push(op2 / op1);
                    }
                }
                else
                {
                    int temp = stoi(itr);
                    st_n.push(temp);
                }

            }

            return st_n.top();
        }
    };
    
int main()
{
    vector<string> val{"1","2","+","3","*","4","-"};
    Solution obj1 = Solution();

    int rst = obj1.evalRPN(val);
    cout << rst;

}