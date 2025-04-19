#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            
            int arrSize = numbers.size();
            int left = 0;
            int right = arrSize - 1 ;

            while (left < arrSize)
            {
                if(numbers[left] + numbers[right] > target)
                {
                    right--;
                }
                else if (numbers[left] + numbers[right] < target)
                {
                    left++;
                }
                else{
                    
                    break;
                }
               
            }
            return vector<int>{left+1 , right+1};
        } 
};

int main(){

    vector<int> abc = vector<int>{1,2,3,4};
    Solution obj1 = Solution();
    vector<int> ans = obj1.twoSum(abc,3);
    cout << "" << ans[0] << "," << ans[1] << endl;

    
}
    