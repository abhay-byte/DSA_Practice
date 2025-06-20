/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                result.push_back(nums[i]);
                break;
            }
        }
    }

    return result;
}
