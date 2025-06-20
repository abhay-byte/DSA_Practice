/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1; // Map value to index

        if (nums[index] < 0) {
            result.push_back(abs(nums[i])); // If negative, it's a duplicate
        } else {
            nums[index] = -nums[index]; // Mark as visited
        }
    }

    return result;
}
