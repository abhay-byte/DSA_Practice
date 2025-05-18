#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySumEqualsK(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumFreq; // To store frequencies of prefix sums
    prefixSumFreq[0] = 1; // Base case: a prefix sum of 0 exists once
    int prefixSum = 0;    // Current prefix sum
    int count = 0;        // Count of subarrays summing to k

    for (int num : nums) {
        prefixSum += num;

        // Check if there is a prefix sum that makes the current subarray sum to k
        if (prefixSumFreq.find(prefixSum - k) != prefixSumFreq.end()) {
            count += prefixSumFreq[prefixSum - k];
        }

        // Update the frequency of the current prefix sum
        prefixSumFreq[prefixSum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << subarraySumEqualsK(nums, k) << endl; // Output: 2
    return 0;
}
