#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int size = nums.size(); 
        int i = 0; int j = 0; int k = 0; int l = 0;
        for( i = 0; i < size; i++)
        {
            for( j = 0; j < size; j++)
            {
                for( k = 0; k < size; k++)
                {
                    for( l = 0; l <size; l++)
                    {
                        if(i==l || j==l || k==l || k==j || k == i || i == j)
                        {
                            continue;
                        }
                        else
                        {
                            if (nums[i]+nums[j]+nums[k]+nums[l] == target)
                            {
                                
                                vector<int> temp = {nums[i],nums[j],nums[k],nums[l]}; 
                                result.push_back(temp);
                            }
                        }
                    }
                }
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {1,0,-1,0,-2,-2};
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