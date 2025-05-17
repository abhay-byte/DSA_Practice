#include <list>

void list_example() {
    list<int> l;

    // Add
    l.push_back(1);   // end
    l.push_front(2);  // front

    // Traverse
    for (int x : l)
        cout << x << " ";

    // Delete
    l.pop_front();    // from front

    // Specialty: Fast insert/delete at both ends, no random access
}

