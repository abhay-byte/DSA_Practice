#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr1(n), arr2(n);

    // Input first array
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    // Input second array
    for (int i = 0; i < n; ++i) {
        cin >> arr2[i];
    }

    // Frequency arrays (Assuming numbers are in range 0 to 1000)
    int freq1[10001] = {0};
    int freq2[10001] = {0};

    // Count frequency in arr1
    for (int i = 0; i < n; ++i) {
        freq1[arr1[i]]++;
    }

    // Count frequency in arr2
    for (int i = 0; i < n; ++i) {
        freq2[arr2[i]]++;
    }

    vector<int> result;

    // Compare frequencies and store common elements
    for (int i = 0; i <= 10000; ++i) {
        int common = min(freq1[i], freq2[i]);
        for (int j = 0; j < common; ++j) {
            result.push_back(i);
        }
    }

    // Print the result in required format
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}
