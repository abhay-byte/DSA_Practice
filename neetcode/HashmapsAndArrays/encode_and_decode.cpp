#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <climits>
#include <cctype>
#include <string>
using namespace std;

class Solution {
    public:
    
        string encode(vector<string>& strs) {
            string encoded_string;

            for(string str: strs)
            {
                string encode = to_string(str.size())+"#"+str;
                encoded_string.append(encode);
            }

            return encoded_string;
            
        }
    
        vector<string> decode(string s) {
            vector<string> res;
            int i = 0;
            while (i < s.size()) {
                int j = i;
                while (j < s.size() && s[j] != '#') {

                    j++;
                }
                int length = stoi(s.substr(i, j - i));
                i = j + 1;
                j = i + length;
                res.push_back(s.substr(i, length));
                i = j;
            }
            return res;
        }
    };
int main() {
        Solution sol;
        vector<string> strs = {"hello", "world", "!"};
        
        string encoded = sol.encode(strs);
        cout << "Encoded: " << encoded << endl;
        
        vector<string> decoded = sol.decode(encoded);
        cout << "Decoded: ";
        for (const string& s : decoded) {
            cout << "[" << s << "] ";
        }
        cout << endl;
        
        return 0;
    }