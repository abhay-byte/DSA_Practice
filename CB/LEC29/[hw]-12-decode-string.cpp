#include <iostream>
#include <stack>
#include <string>
using namespace std;

// https://leetcode.com/problems/decode-string/
class Solution {
public:
    string decodeString(string s) {
        stack<int> cnt;
        stack<string> frags;
        string curr;
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                cnt.push(num);
                frags.push(curr);
                num = 0;
                curr.clear();
            } else if (c == ']') {
                int k = cnt.top(); cnt.pop();
                string temp;
                temp.reserve(curr.size() * k);
                while (k--) temp += curr;
                curr = frags.top() + temp;
                frags.pop();
            } else {
                curr.push_back(c);
            }
        }
        return curr;
    }
};

int main() {
    Solution sol;
    string s1 = "3[a]2[bc]";
    string s2 = "3[a2[c]]";
    string s3 = "2[abc]3[cd]ef";

    cout << sol.decodeString(s1) << endl; // Expected: aaabcbc
    cout << sol.decodeString(s2) << endl; // Expected: accaccacc
    cout << sol.decodeString(s3) << endl; // Expected: abcabccdcdcdef

    return 0;
}
