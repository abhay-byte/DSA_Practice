/*
Time Complexity: O(N^3), 2 Nested Loops + Two Pointer Approach
Space Complexity: O(N), Hash Table Used

Time Optimized Approach
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        set<vector<int>> unique;
        sort(nums.begin(),nums.end());
        int size = nums.size(); 
        int i = 0; int j = 0;
        for( i = 0; i < size-3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for( j = i+1; j < size-2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j+1;
                int right = size-1;
                while(left<right)
                {
                    long long sum = (long long)nums[i]+(long long)nums[j]+(long long)nums[left]+(long long)nums[right];

                    if (sum < target) {
                        left++;
                    } else if (sum > target) {
                        right--;
                    } 
                    else 
                    {
                        if (sum == target)
                            {
                                vector<int> temp = {nums[i],nums[j],nums[left],nums[right]}; 
                                unique.insert(temp);
                                while (left < right && nums[left] == nums[left + 1]) left++;
                                while (left < right && nums[right] == nums[right - 1]) right--;
                                left++;
                                right--;
                            }
                    }

                }
            }
        }

        for (auto i : unique)
        {
            result.push_back(i);
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;

    Solution obj = Solution();

    vector<vector<int>> solution = obj.fourSum(nums,target);

    for (vector<int> i : solution)
    {
        for (int j : i)
        {
            cout << j << " ";
        }

        cout << endl;
    }
    cout << solution.size();
}