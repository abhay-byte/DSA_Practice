#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Custom comparator to decide the order based on string comparison
bool compare(string a, string b) {
    return a + b > b + a;
}

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Sort using custom comparator
        sort(arr.begin(), arr.end(), compare);

        // Edge case: all numbers are 0
        if (arr[0] == "0") {
            cout << "0" << endl;
        } else {
            for (string s : arr) {
                cout << s;
            }
            cout << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
