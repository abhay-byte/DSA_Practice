#include <iostream>
#include <vector>
using namespace std;

void printSubsets(vector<int>& arr, int index, vector<int>& current, int sum, int target) {
    // Base case
    if (index == arr.size()) {
        if (sum == target) {
            for (int i = 0; i < current.size(); i++) {
                cout << current[i];
                if (i != current.size() - 1) cout << " ";
            }
            cout << "  ";
        }
        return;
    }

    // Recursion case: include current element
    current.push_back(arr[index]);
    printSubsets(arr, index + 1, current, sum + arr[index], target);
    current.pop_back();

    // Recursion case: exclude current element
    printSubsets(arr, index + 1, current, sum, target);
}

int countSubsets(vector<int>& arr, int index, int sum, int target) {
    // Base case
    if (index == arr.size()) {
        return (sum == target) ? 1 : 0;
    }

    // Recursion case: include current element
    int include = countSubsets(arr, index + 1, sum + arr[index], target);

    // Recursion case: exclude current element
    int exclude = countSubsets(arr, index + 1, sum, target);

    return include + exclude;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cin >> target;

    vector<int> current;
    printSubsets(arr, 0, current, 0, target);
    cout << endl;

    int count = countSubsets(arr, 0, 0, target);
    cout << count << endl;

    return 0;
}
