#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> lst = {10, 40, 30, 50, 20, 60};

    // Sort list using std::list::sort
    lst.sort();

    cout << "Sorted list: ";
    for (int num : lst) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

