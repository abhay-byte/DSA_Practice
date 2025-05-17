#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            vector<int> result;
            for(int itr: nums)
            {
                result.push_back(itr*itr);
            }

            sort(result.begin(),result.end());
            return result;
        }
    };