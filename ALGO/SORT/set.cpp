#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s = {10, 40, 30, 50, 20, 60};

    // Set is always sorted in ascending order by default
    cout << "Sorted set: ";
    for (int num : s) {
        cout << num << " ";
    }
    cout << endl;

    set<int, greater<int>> s1 = {10, 40, 30, 50, 20, 60};

    // Sorting in descending order
    cout << "Sorted set (descending): ";
    for (int num : s1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

