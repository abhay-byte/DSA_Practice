/*
Time Complexity: O(N^2), One Loop + Two Pointer Approach
Space Complexity: O(1)

Optimized Approach
*/


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int closestSum = INT_MAX;
        int leastDifference = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size-2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i+1;
            int right = size-1;
            while(left < right)
            {
                int currentSum = nums[i] + nums[left] + nums[right];
                int currentDifference = abs(currentSum - target);

                if (currentDifference < leastDifference) {
                    closestSum = currentSum;
                    leastDifference = currentDifference;
                }
                if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closestSum;
    }
};

int main()
{
    vector<int> nums = {1,1,1,0};
    int target = 1;

    Solution obj = Solution();

    int solution = obj.threeSumClosest(nums,target);
    cout << solution;
}