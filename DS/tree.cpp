#include <map>
#include <iostream>
using namespace std;

void map_as_tree() {
    map<int, string> treeMap;

    // Add (Insert)
    treeMap[3] = "Three";
    treeMap[1] = "One";
    treeMap[5] = "Five";

    // Traverse (Inorder because it's tree)
    for (auto &p : treeMap)
        cout << p.first << ": " << p.second << "\n";

    // Check existence
    if (treeMap.count(3)) cout << "Key 3 exists\n";

    // Delete
    treeMap.erase(1);
}

using namespace std;

void set_as_tree() {
    set<int> treeSet;

    // Add
    treeSet.insert(10);
    treeSet.insert(5);
    treeSet.insert(15);

    // Traverse (Sorted order)
    for (int val : treeSet)
        cout << val << " ";

    // Check
    if (treeSet.count(10)) cout << "\n10 exists\n";

    // Delete
    treeSet.erase(5);
}

