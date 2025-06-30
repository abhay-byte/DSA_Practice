#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> result;
    for (int itr : nums) {
        result.push_back(itr * itr);
    }
    sort(result.begin(), result.end());
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    vector<int> result = sortedSquares(nums);

    for (int val : result)
        cout << val << " ";

    return 0;
}
