#include <set>
#include <iostream>
using namespace std;

void set_example() {
    set<int> s;

    // Add
    s.insert(10);
    s.insert(5);
    s.insert(10); // duplicates not added

    // Traverse (sorted)
    for (int x : s)
        cout << x << " ";

    // Delete
    s.erase(5);

    // Specialty: unique + sorted
}
//if(my_set.insert("value").second == false)
// Check element in set
void set_check_example() {
    set<int> s = {10, 20, 30};

    if (s.count(20)) cout << "20 is in set\n";
    if (s.find(100) == s.end()) cout << "100 is not in set\n";
}
