#include <map>
using namespace std;

void map_example() {
    map<string, int> mp;

    // Add
    mp["zebra"] = 1;
    mp["apple"] = 5;

    // Traverse (sorted by key)
    for (auto &p : mp)
        cout << p.first << ": " << p.second << endl;

    // Delete
    mp.erase("zebra");

    // Specialty: Always sorted, O(log n) insert/search
}

//Check key in map
void map_check_example() {
    map<int, string> mp;
    mp[1] = "A";
    mp[2] = "B";

    if (mp.count(1)) cout << "Key 1 exists\n";
    if (mp.find(3) == mp.end()) cout << "Key 3 not found\n";
}
