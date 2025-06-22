#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i <= n; ++i) {
        bool found = false;
        for (int num : nums) {
            if (num == i) {
                found = true;
                break;
            }
        }
        if (!found) return i;
    }
    return -1;
}
