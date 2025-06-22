#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        // Array to count frequencies of characters (26 for lowercase a-z)
        int charCount[26] = {0};

        // Increment counts for `s` and decrement counts for `t`
        for (int i = 0; i < s.size(); ++i) {
            charCount[s[i] - 'a']++;
            charCount[t[i] - 'a']--;
        }

        // Check if all counts are zero
        for (int count : charCount) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};
