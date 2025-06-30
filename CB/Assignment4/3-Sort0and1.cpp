#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    // Input array
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int left = 0, right = n - 1;

    // Two-pointer approach to move 0s to the left and 1s to the right
    while (left < right) {
        if (arr[left] == 1 && arr[right] == 0) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
        if (arr[left] == 0) left++;
        if (arr[right] == 1) right--;
    }

    // Output the sorted array
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
