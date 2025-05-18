#include <iostream>
#include <climits>
#include <vector>
using namespace std;

 int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    // Step 1: Compute maximum subarray sum using Kadane's algorithm
    int maxSoFar = nums[0];
    int maxEndingHere = nums[0];

    // Step 2: Compute minimum subarray sum using a similar Kadane's algorithm
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

    // Step 3: Handle the edge case where all elements are negative
    if (maxSoFar < 0) return maxSoFar;

    // Step 4: Return the maximum of maxSoFar (non-wrapping) and totalSum - minSoFar (wrapping)
    return max(maxSoFar, totalSum - minSoFar);
    }

int main()
{
    vector<int> arr = {1,3,0,5,6,7,-5,-8,1,3};
    cout << maxSubarraySumCircular(arr);
}

