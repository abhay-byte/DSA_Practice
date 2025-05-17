#include <unordered_map>
#include <iostream>
using namespace std;

void unordered_map_example() {
    unordered_map<string, int> umap;

    // Add
    umap["apple"] = 2;
    umap["banana"] = 3;

    // Traverse
    for (auto &p : umap)
        cout << p.first << ": " << p.second << endl;

    // Delete
    umap.erase("apple");

    // Specialty: O(1) average access time
    if (umap.count("banana")) cout << "banana exists\n";
}

//Check key in unordered_map
void unordered_map_check_example() {
    unordered_map<string, int> ump;
    ump["apple"] = 5;

    if (ump.count("apple")) cout << "apple exists\n";
    if (ump.find("banana") == ump.end()) cout << "banana not found\n";
}

