#include <iostream>
#include <vector>

using namespace std;

int searchRotatedSortedArray(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        // Determine which half is sorted
        if (nums[left] <= nums[mid]) { // Left half is sorted
            if (target >= nums[left] && target < nums[mid]) {
                right = mid - 1; // Target is in the sorted left half
            } else {
                left = mid + 1; // Target is in the unsorted right half
            }
        } else { // Right half is sorted
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1; // Target is in the sorted right half
            } else {
                right = mid - 1; // Target is in the unsorted left half
            }
        }
    }

    return -1; // Target not found
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    cout << searchRotatedSortedArray(nums, target) << endl;

    return 0;
}
