#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string filtered = "";

        // Step 1: Filter the string
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }

        // Step 2: Reverse the filtered string
        string reversed = filtered;
        reverse(reversed.begin(), reversed.end());

        // Step 3: Check if filtered and reversed strings are the same
        return filtered == reversed;
    }
};
