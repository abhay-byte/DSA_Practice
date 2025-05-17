#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    unordered_set<int> us = {10, 40, 30, 50, 20, 60};

    // Copy the elements to a vector
    vector<int> vec(us.begin(), us.end());

    // Sort the vector
    sort(vec.begin(), vec.end());

    cout << "Sorted unordered_set: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

