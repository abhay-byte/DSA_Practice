#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> remainderIndex;
    remainderIndex[0] = -1; // To handle subarrays starting from index 0
    int prefixSum = 0;

    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];

        // Compute the remainder of the prefix sum modulo k
        int remainder = k != 0 ? (prefixSum % k + k) % k : prefixSum;

        // Check if the remainder has been seen before
        if (remainderIndex.find(remainder) != remainderIndex.end()) {
            if (i - remainderIndex[remainder] > 1) {
                return true; // Subarray length is at least 2
            }
        } else {
            remainderIndex[remainder] = i; // Store the index of this remainder
        }
    }

    return false; // No good subarray found
}

int main() {
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;
    cout << boolalpha << checkSubarraySum(nums, k) << endl; // Output: true

    nums = {23, 2, 6, 4, 7};
    k = 13;
    cout << boolalpha << checkSubarraySum(nums, k) << endl; // Output: false

    return 0;
}
