#include <iostream>
#include <vector>

bool canJumpGreedy(const std::vector<int>& nums) {
    int maxReach = 0; // Tracks the furthest index reachable so far.
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (i > maxReach) {
            return false; // If current index is beyond the max reachable index, return false.
        }
        maxReach = std::max(maxReach, i + nums[i]);
        if (maxReach >= n - 1) {
            return true; // If the last index is reachable, return true.
        }
    }
    return true;
}

int main() {
    std::vector<int> nums = {2, 3, 1, 1, 4};
    std::cout << "Can Jump (Greedy): " << (canJumpGreedy(nums) ? "true" : "false") << std::endl;
    return 0;
}
