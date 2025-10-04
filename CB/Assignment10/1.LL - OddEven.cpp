//https://hack.codingblocks.com/app/contests/7854/28/problem

#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeOddsBeforeEvens(const vector<int>& arr) {
    vector<int> odds, evens;

    for (int num : arr) {
        if (num % 2 == 1) {
            odds.push_back(num);
        } else {
            evens.push_back(num);
        }
    }

    // Concatenate odds and evens
    odds.insert(odds.end(), evens.begin(), evens.end());
    return odds;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = rearrangeOddsBeforeEvens(arr);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
