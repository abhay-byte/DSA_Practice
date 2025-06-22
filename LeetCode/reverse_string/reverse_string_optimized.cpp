#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;

        // Swap characters from both ends
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
