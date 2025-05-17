//First Attempt
/*
#include<vector>
#include<unorderedmap>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<unorderedmap<char,int>> mapArray;
        vector<vector<string>> result;
        int j = 0;

        for (string i: strs)
        {
          for (char k: i)
          {
            if(mapArray[j].find(k) != mapArray.end())
            {
              mapArray[j][k] += 1;
            }
            else {
              mapArray[j][k] = 1;  
            }

          }
          j++;
        }

        vector<string> temp;
          
        for (unorderedmap<char,int>l : mapArray)
        {
          temp.clear();
          for(unorderedmap <char,int> m : mapArray)
          {
            if(l==m)
            {
              temp.push_back(m);
            }
          }
          temp.push_back(l);
          result.push_back(temp);
        }

        return result;
};
*/
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (const string& word : strs) {
            // Create a frequency key for the word (26 letters)
            int count[26] = {0};
            for (char c : word) {
                count[c - 'a']++;
            }

            // Convert count array to a string key
            string key;
            for (int i = 0; i < 26; ++i) {
                key += to_string(count[i]) + '#';  // '#' separates counts
            }

            anagramGroups[key].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }

        return result;
    }
};

