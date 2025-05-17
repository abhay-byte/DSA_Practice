#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec = {10, 40, 30, 50, 20, 60};

    // Sort vector using std::sort
    sort(vec.begin(), vec.end());

    cout << "Sorted vector: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

