#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

       
    }
};

int main()
{
    vector<int> nums = {0,1,1,1,1,1,0,0,0,0,0};
    Solution obj = Solution();

    cout << obj.findMaxLength(nums) <<  endl;
}