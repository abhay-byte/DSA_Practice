#include<unordered_map>
using namespace std;
class Solution {
public:
  unordered_map<char,int> hashTableForS; 
  unordered_map<char,int> hashTableForT;
  bool isAnagram(string s, string t) {
      
      for (int i : s)
      {
        if (hashTableForS.find(i) != hashTableForS.end())
          hashTableForS[i] = hashTableForS[i]+1;
        else {
          hashTableForS[i] = 1;
        }
      }

      for (int i : t)
      {
        if (hashTableForT.find(i) != hashTableForT.end())
          hashTableForT[i] = hashTableForT[i]+1;
        else {
          hashTableForT[i] = 1;
        }
      }

      if (hashTableForT == hashTableForS)
      {
        return true;
      }
    }
};
