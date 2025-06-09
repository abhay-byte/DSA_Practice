/*
Time Complexity: O(N^4), Four Nested Loops
Space Complexity: O(N), Hash Table Used

Brute Force Approach
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
        int i = 0; int j = 0; int k = 0; int l = 0;
        for( i = 0; i < size-3; i++)
        {
            for( j = i+1; j < size-2; j++)
            {
                for( k = j+1; k < size-1; k++)
                {
                    for( l = k+1; l <size; l++)
                    {
                            if (nums[i]+nums[j]+nums[k]+nums[l] == target)
                            {
                                vector<int> temp = {nums[i],nums[j],nums[k],nums[l]}; 
                                unique.insert(temp);
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