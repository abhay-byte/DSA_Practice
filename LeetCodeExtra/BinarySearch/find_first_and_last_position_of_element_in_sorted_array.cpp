#include <iostream>
#include <vector>
using namespace std;

vector<int> firstAndLastOccurrence(vector<int>& nums, int target) {
    vector<int> ans{-1, -1};
    int n = nums.size();
    
    // Binary search for the first occurrence
    int s = 0, e = n - 1;
    while (s <= e) {
        int m = s + (e - s) / 2;
        if (nums[m] == target) {
            ans[0] = m; // Update the first occurrence
            e = m - 1;  // Continue searching in the left half
        } else if (nums[m] < target) {
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    
    // Binary search for the last occurrence
    s = 0, e = n - 1;
    while (s <= e) {
        int m = s + (e - s) / 2;
        if (nums[m] == target) {
            ans[1] = m; // Update the last occurrence
            s = m + 1;  // Continue searching in the right half
        } else if (nums[m] < target) {
            s = m + 1;
        } else {
            e = m - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 3, 3, 4, 5, 5, 5, 6, 6, 7};
    int target = 3;
    vector<int> result = firstAndLastOccurrence(arr, target);
    cout << result[0] << " " << result[1] << endl; // Output: 2 4
    return 0;
}
