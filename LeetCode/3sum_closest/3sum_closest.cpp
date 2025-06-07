#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> sum;
        for (int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                for (int k = 0; k < size; k++)
                {
                    if(i == k || j == k || j == i)
                    {
                        continue;
                    }
                    else
                    {
                        if(nums[i]+nums[j]+nums[k]!=target)
                            sum.push_back(nums[i]+nums[j]+nums[k]);
                    }
                }
            }
        }

        int result = INT_MAX;

        for(int i : sum)
        {
            int diff = abs(target - i);
            result = min(diff,result);
        }

        return result;
        
    }
};

int main()
{
    vector<int> nums = {-1,2,1,-4};
    int target = 1;

    Solution obj = Solution();

    int solution = obj.threeSumClosest(nums,target);
    cout << solution;
}