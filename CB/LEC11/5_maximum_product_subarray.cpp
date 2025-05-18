#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int maxSubArrayProduct(vector<int> nums){
        int n = nums.size();
        if (n == 0) return 0;

        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int result = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < 0)
                swap(maxSoFar, minSoFar); // Swap when encountering a negative number

            maxSoFar = max(nums[i], maxSoFar * nums[i]);
            minSoFar = min(nums[i], minSoFar * nums[i]);

            result = max(result, maxSoFar); // Update the overall maximum product
        }

        return result;
}

int main()
{
    vector<int> arr = {1,3,0,5,6,7,-5,-8,1,3};
    cout << maxSubArrayProduct(arr);
}

