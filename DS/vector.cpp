#include <vector>
#include <iostream>
using namespace std;

void vector_example() {
    vector<int> v;

    // Add
    v.push_back(10);
    v.push_back(20);

    // Traverse
    for (int x : v)
        cout << x << " ";

    // Delete last
    v.pop_back();

    // Specialty: Fast random access (v[i]), auto-resizing
}

