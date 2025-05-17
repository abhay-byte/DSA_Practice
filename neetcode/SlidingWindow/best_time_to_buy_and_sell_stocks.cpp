#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <climits>
#include <string>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int l = 0, r = 1;
            int maxP = 0;
    
            while (r < prices.size()) {
                if (prices[l] < prices[r]) {
                    int profit = prices[r] - prices[l];
                    maxP = max(maxP, profit);
                } else {
                    l = r;
                }
                r++;
            }
            return maxP;
        }
    };