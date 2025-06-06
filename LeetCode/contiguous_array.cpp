#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> prefixSumMap;
        prefixSumMap[0] = -1; // Initialize to handle subarrays starting from index 0
        int prefixSum = 0;
        int maxLength = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Update prefix sum: +1 for 1, -1 for 0
            prefixSum += (nums[i] == 1) ? 1 : -1;

            // Check if the prefixSum has been seen before
            if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
                // Update maxLength with the distance between indices
                maxLength = max(maxLength, i - prefixSumMap[prefixSum]);
            } else {
                // Store the first occurrence of this prefixSum
                prefixSumMap[prefixSum] = i;
            }
        }

        return maxLength;
    }
};

int main()
{
    vector<int> nums = {0,1,1,1,1,1,0,0,0,0,0};
    Solution obj = Solution();

    cout << obj.findMaxLength(nums) <<  endl;
}