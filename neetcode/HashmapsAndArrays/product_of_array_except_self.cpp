/*#include<vector>
#include<unordered_map>
using namespace std ;

class Solution {

public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> result;
       vector<int> prefixArr;
       vector<int> suffixArr;
       
       int j = 1;
       for (int i = -1; i <= nums.size()-2; i++)
       {
         if (i < 0)
         {
           prefixArr.push_back(1);
         }
         else {
            j *= nums[i];
            prefixArr.push_back(j);
         }
       }

       j = 1;

      for (i = nums.size(); i >= 1; --i) {
          if (i == nums.size())
          {
             prefixArr.push_back(1);
          }
          else {
              j *= nums[i];
              prefixArr.push_back(j);
          }

      }

      for (i = 0; i < nums.size(); i++)
      {
        result.push_back(prefixArr[i] * suffixArr[i]);
      }
      return result;
    }
};*/ 
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> prefixArr(n);
        vector<int> suffixArr(n);

        // Calculate prefix products
        prefixArr[0] = 1;
        for (int i = 1; i < n; i++) {
            prefixArr[i] = prefixArr[i - 1] * nums[i - 1];
        }

        // Calculate suffix products
        suffixArr[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            suffixArr[i] = suffixArr[i + 1] * nums[i + 1];
        }

        // Calculate the result
        for (int i = 0; i < n; i++) {
            result[i] = prefixArr[i] * suffixArr[i];
        }

        return result;
    }
};
