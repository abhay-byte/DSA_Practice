#include <iostream>
#include <vector>
#include <algorithm>

int partitionDisjoint(const std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        int maxLeft = *std::max_element(nums.begin(), nums.begin() + i);
        int minRight = *std::min_element(nums.begin() + i, nums.end());
        if (maxLeft <= minRight) {
            return i;
        }
    }
    return -1; // This case will not occur due to guaranteed partitioning.
}

int main() {
    std::vector<int> nums = {5, 0, 3, 8, 6};
    std::cout << "Brute Force Partition Index: " << partitionDisjoint(nums) << std::endl;
    return 0;
}
