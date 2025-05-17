#include <exception>
#include<vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool hasDuplicate(vector<int>& nums){
    unordered_set<int> set;
    for (int i : nums)
    { 
      try
      {
        auto result = set.insert(i);
        bool condition = result.second;
        if(condition)
          continue;
        else {
          return true;
        }  
        
      }
      catch (exception e)
      {
          return false;
      }
    }
    return false;
  }
};
