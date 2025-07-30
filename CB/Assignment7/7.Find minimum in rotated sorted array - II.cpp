#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinRotatedSortedArray(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            // Minimum element is in the right half
            left = mid + 1;
        } else if (nums[mid] < nums[right]) {
            // Minimum element is in the left half or is the mid element
            right = mid;
        } else {
            // nums[mid] == nums[right]
            // We can't be sure which side the minimum is on, so reduce the search space
            right--; // Crucial for handling duplicates.
        }
    }

    return nums[left];
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << findMinRotatedSortedArray(nums) << endl;

    return 0;
}
