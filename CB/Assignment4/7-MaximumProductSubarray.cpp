#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int maxSubArrayProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    int maxSoFar = nums[0];
    int minSoFar = nums[0];
    int result = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] < 0)
            swap(maxSoFar, minSoFar); // handle negative numbers

        maxSoFar = max(nums[i], maxSoFar * nums[i]);
        minSoFar = min(nums[i], minSoFar * nums[i]);

        result = max(result, maxSoFar);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << maxSubArrayProduct(arr) << endl;
    return 0;
}
