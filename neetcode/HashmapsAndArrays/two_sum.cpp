#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
  unordered_map<int,int> hashtable;
    vector<int> twoSum(vector<int>& num, int index) {
      
      int j = 0;
      for (int i : nums)
      {
        int diff = target - i;
        
        if(hashtable.find(diff) != hashtable.end())
          return {hashtable[diff],j};
        hashtable[i]=j;
        j++;
      }

    return {} ;

    }
};
