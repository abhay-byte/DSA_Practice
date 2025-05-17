#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    unordered_map<int, string> um = {{3, "three"}, {1, "one"}, {4, "four"}, {2, "two"}};

    // Copy the key-value pairs to a vector
    vector<pair<int, string>> vec(um.begin(), um.end());

    // Sort the vector by key
    sort(vec.begin(), vec.end());

    cout << "Sorted unordered_map by key: ";
    for (const auto& pair : vec) {
        cout << pair.first << " " << pair.second << " ";
    }
    cout << endl;

    return 0;
}

