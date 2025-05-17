#include <vector>
#include <algorithm> 
#include <iostream> 
using namespace std;
class Solution {
    public:
        int maximumPossibleSize(vector<int>& nums) {
            vector<long long> res;
            for (int num : nums) {
                long long current_max = num;
                while (!res.empty() && res.back() > current_max) {
                    current_max = max(current_max, res.back());
                    res.pop_back();
                }
                res.push_back(current_max);
            }
            return res.size();
        }
    };
    

