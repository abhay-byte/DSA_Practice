#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    int maxSoFar = nums[0];
    int maxEndingHere = nums[0];

    int minSoFar = nums[0];
    int minEndingHere = nums[0];
    int totalSum = nums[0];

    for (int i = 1; i < n; i++) {
        maxEndingHere = max(maxEndingHere + nums[i], nums[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
        
        minEndingHere = min(minEndingHere + nums[i], nums[i]);
        minSoFar = min(minSoFar, minEndingHere);
        
        totalSum += nums[i];
    }

    // If all numbers are negative, return maxSoFar (non-wrapping case)
    if (maxSoFar < 0) return maxSoFar;

    // Return the max of non-wrapping and wrapping subarray sums
    return max(maxSoFar, totalSum - minSoFar);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    cout << maxSubarraySumCircular(nums) << endl;

    return 0;
}
