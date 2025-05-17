#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long hours_needed = 0;

            for (int bananas : piles) {
                hours_needed += (bananas + mid - 1) / mid; // equivalent to ceil(bananas / mid)
            }

            if (hours_needed <= h) {
                result = mid;        // trying to find a smaller valid speed
                right = mid - 1;
            } else {
                left = mid + 1;      // increase speed
            }
        }

        return result;
    }
};

    
int main()
{
    vector<int> piles{1,4,3,2};
    int h = 9;
    Solution obj = Solution();
    int min_hours = obj.minEatingSpeed(piles,h);
    cout << min_hours;
}