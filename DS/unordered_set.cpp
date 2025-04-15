#include <unordered_set>

void unordered_set_example() {
    unordered_set<int> us;

    // Add
    us.insert(3);
    us.insert(1);
    us.insert(3);

    // Traverse (no order)
    for (int x : us)
        cout << x << " ";

    // Delete
    us.erase(1);

    // Specialty: O(1) average time, unique only
}

//Check element in unordered_set
void unordered_set_check_example() {
    unordered_set<int> us = {1, 2, 3};

    if (us.count(2)) cout << "2 exists\n";
    else cout << "2 does not exist\n";
}
