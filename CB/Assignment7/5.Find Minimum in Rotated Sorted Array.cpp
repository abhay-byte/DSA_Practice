#include <iostream>
#include <vector>

using namespace std;

int findMinRotatedSortedArray(const vector<long long>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            // Minimum element is in the right half
            left = mid + 1;
        } else {
            // Minimum element is in the left half (including mid)
            right = mid;
        }
    }

    return nums[left];
}

int main() {
    int n;
    cin >> n;

    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << findMinRotatedSortedArray(nums) << endl;

    return 0;
}
