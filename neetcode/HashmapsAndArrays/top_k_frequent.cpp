#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int> frequency;
      for (int i : nums)
      {
        if (frequency.find(i) != frequency.end())
        {
          frequency[i] += 1;
        }

        else {

          frequency[i] = 1;

        }

      }

      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

      for (auto& [num, freq] : frequency) {
            minHeap.push({freq, num});
            if (minHeap.size() > k) {
                minHeap.pop(); // remove the least frequent element
            }
        }

      vector<int> result;
      while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
    
    }
};
