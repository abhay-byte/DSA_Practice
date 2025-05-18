#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countGoodSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> freq; // Frequency map to count occurrences
    int left = 0, pairs = 0, goodSubarrays = 0;

    for (int right = 0; right < n; ++right) {
        // Add the current element to the frequency map
        freq[nums[right]]++;

        // Update the number of pairs contributed by nums[right]
        pairs += freq[nums[right]] - 1;

        // Shrink the window until the number of pairs is at least k
        while (pairs >= k) {
            goodSubarrays += (n - right); // All subarrays starting at 'left' and ending at 'right' are good
            freq[nums[left]]--;
            pairs -= freq[nums[left]]; // Update pairs after removing nums[left]
            left++;
        }
    }

    return goodSubarrays;
}

int main() {
    vector<int> nums = {3, 1, 4, 3, 2, 2, 4};
    int k = 2;
    cout << countGoodSubarrays(nums, k) << endl; // Output: 4
    return 0;
}
