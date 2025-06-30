#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    // Input array
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    sort(arr.begin(), arr.end());  // Sort to use two-pointer

    bool found = false;

    for (int i = 0; i < n - 2; ++i) {
        // Skip duplicates for the first element
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == target) {
                cout << arr[i] << ", " << arr[j] << " and " << arr[k] << endl;
                found = true;

                j++;
                k--;

                // Skip duplicates for second and third elements
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;

            } else if (sum < target) {
                j++;
            } else {
                k--;
            }
        }
    }


    return 0;
}
