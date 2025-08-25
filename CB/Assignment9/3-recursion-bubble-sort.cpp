#include <iostream>
#include <vector>
using namespace std;

void bubbleSortRecursive(vector<int>& arr, int n) {
    // Base case
    if (n == 1) return;

    // One pass of bubble sort
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    // Recursion case: sort first n-1 elements
    bubbleSortRecursive(arr, n - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSortRecursive(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
