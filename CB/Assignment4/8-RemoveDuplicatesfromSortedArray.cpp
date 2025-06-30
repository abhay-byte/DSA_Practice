#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int uniqueIndex = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[uniqueIndex]) {
            ++uniqueIndex;
            nums[uniqueIndex] = nums[i];
        }
    }
    return uniqueIndex + 1;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    int k = removeDuplicates(nums);

    cout << k << endl;
    for (int i = 0; i < k; ++i)
        cout << nums[i] << " ";

    return 0;
}
