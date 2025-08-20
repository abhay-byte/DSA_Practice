#include <iostream>
#include <vector>
using namespace std;

int findMinIndex(vector<int>& arr, int start, int n) {
    int minIndex = start;
    for (int i = start + 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

void selectionSortRecursive(vector<int>& arr, int start, int n) {
    // Base case
    if (start >= n - 1) return;

    // Recursion case: find index of min element
    int minIndex = findMinIndex(arr, start, n);

    // Swap with start element
    if (minIndex != start) {
        swap(arr[start], arr[minIndex]);
    }

    // Recurse for the remaining array
    selectionSortRecursive(arr, start + 1, n);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSortRecursive(arr, 0, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
