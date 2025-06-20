/*
Time Complexity: O(nlogn)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            result.push_back(nums[i]);
        }
    }

    return result;
}
