#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;


class Solution {
public:

  unordered_set<int> vectorToUnorderedSet(const vector<int>& vec) {
    unordered_set<int> uset;
    for (int num : vec) {
        uset.insert(num);
    }
    return uset;
}

priority_queue<int, vector<int>, greater<int>> unorderedSetToPriorityQueue(const unordered_set<int>& uset) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int num : uset) {
        pq.push(num);
    }
    return pq;
}

int findLongestConsecutiveLength(priority_queue<int, vector<int>, greater<int>> pq) {
    if (pq.empty()) {
        return 0;
    }

    int prev = pq.top();
    pq.pop();
    int currentLength = 1;
    int maxLength = 1;

    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        if (curr == prev + 1) {
            currentLength++;
        } else if (curr != prev) {
            currentLength = 1;
        }
        prev = curr;
        maxLength = max(maxLength, currentLength);
    }

    return maxLength;
}
  
    int longestConsecutive(vector<int>& nums) {
     
      unordered_set<int> numberSet = vectorToUnorderedSet(nums);
       priority_queue<int, vector<int>, greater<int>> numberQueue = unorderedSetToPriorityQueue(numberSet);
           int largestSequential = findLongestConsecutiveLength(numberQueue);

           return largestSequential;

    }
};

