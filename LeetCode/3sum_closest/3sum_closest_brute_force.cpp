/*
Time Complexity: O(N^3), Three Nested Loops
Space Complexity: O(1)

Brute Force Approach
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
        for (int i = 0; i < size-2; i++)
        {
            for(int j = i+1; j < size-1; j++)
            {
                for (int k = j+1; k < size; k++)
                {
                    int currentSum = nums[i] + nums[j] + nums[k];
                    int currentDifference = abs(currentSum - target);

                    if (currentDifference < leastDifference) {
                        closestSum = currentSum;
                        leastDifference = currentDifference;
                    }
                    
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