#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> prefixSumMap;
        prefixSumMap[0] = -1;
        int prefixSum = 0;
        int maxLength = 0;

        for (int i = 0; i < nums.size(); i++) {
           
            prefixSum += (nums[i] == 1) ? 1 : -1;

            
            if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
               
                maxLength = max(maxLength, i - prefixSumMap[prefixSum]);
            } else {
                
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