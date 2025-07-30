#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int smallestDivisor(vector<int>& nums, int threshold) {
    int left = 1;
    sort(nums.begin(), nums.end());
    int right = nums.back(); // The largest number in the array is the maximum possible divisor
    int ans = right; // Initialize with the maximum possible divisor

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int sum = 0;

        for (int num : nums) {
            sum += ceil((double)num / mid);
        }

        if (sum <= threshold) {
            ans = mid;
            right = mid - 1; // Try to find a smaller divisor
        } else {
            left = mid + 1; // Divisor is too small, increase it
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int threshold;
    cin >> threshold;

    cout << smallestDivisor(nums, threshold) << endl;

    return 0;
}
