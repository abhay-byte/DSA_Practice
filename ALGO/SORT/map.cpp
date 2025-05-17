#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, string> m = {{3, "three"}, {1, "one"}, {4, "four"}, {2, "two"}};

    // Map is always sorted by key in ascending order by default
    cout << "Sorted map: ";
    for (const auto& pair : m) {
        cout << pair.first << " " << pair.second << " ";
    }
    cout << endl;

    return 0;
}

