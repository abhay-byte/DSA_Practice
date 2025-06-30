#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    // Input the array
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    sort(arr.begin(), arr.end());  // Sort to apply two-pointer approach

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            cout << arr[left] << " and " << arr[right] << endl;

            // Move both pointers and skip duplicates
            int l_val = arr[left], r_val = arr[right];
            while (left < right && arr[left] == l_val) left++;
            while (left < right && arr[right] == r_val) right--;

        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return 0;
}
