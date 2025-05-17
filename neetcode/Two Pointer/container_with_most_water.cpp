#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int left = 0, right = height.size() - 1;
            int maxArea = 0;
    
            while (left < right) {
                int h = min(height[left], height[right]);
                int w = right - left;
                maxArea = max(maxArea, h * w);
    
                if (height[left] < height[right])
                    left++;
                else
                    right--;
            }
    
            return maxArea;
        }
    };

int main(){

    vector<int> heights{1,7,2,5,4,7,3,6};

    Solution obj1 = Solution();

    obj1.maxArea(heights);

}