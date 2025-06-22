#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // Move left pointer to next alphanumeric character
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Move right pointer to previous alphanumeric character
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare characters
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
