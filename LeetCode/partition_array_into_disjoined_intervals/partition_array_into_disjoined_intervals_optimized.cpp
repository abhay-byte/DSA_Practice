#include <iostream>
#include <vector>
#include <algorithm>

int partitionDisjoint(const std::vector<int>& nums) {
    int n = nums.size();
    int maxLeft = nums[0];
    int overallMax = nums[0];
    int partitionIdx = 0;

    for (int i = 1; i < n; ++i) {
        overallMax = std::max(overallMax, nums[i]);
        if (nums[i] < maxLeft) {
            maxLeft = overallMax;
            partitionIdx = i;
        }
    }
    return partitionIdx + 1;
}

int main() {
    std::vector<int> nums = {5, 0, 3, 8, 6};
    std::cout << "Optimized Partition Index: " << partitionDisjoint(nums) << std::endl;
    return 0;
}
